#include "selfdrive/ui/qt/onroad/onroad_home.h"

#include <QPainter>
#include <QStackedLayout>

#ifdef ENABLE_MAPS
#include "selfdrive/ui/qt/maps/map_helpers.h"
#include "selfdrive/ui/qt/maps/map_panel.h"
#endif

#include "selfdrive/ui/qt/util.h"

OnroadWindow::OnroadWindow(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *main_layout  = new QVBoxLayout(this);
  main_layout->setMargin(UI_BORDER_SIZE);
  QStackedLayout *stacked_layout = new QStackedLayout;
  stacked_layout->setStackingMode(QStackedLayout::StackAll);
  main_layout->addLayout(stacked_layout);

  nvg = new AnnotatedCameraWidget(VISION_STREAM_ROAD, this);

  QWidget * split_wrapper = new QWidget;
  split = new QHBoxLayout(split_wrapper);
  split->setContentsMargins(0, 0, 0, 0);
  split->setSpacing(0);
  split->addWidget(nvg);

  if (getenv("DUAL_CAMERA_VIEW")) {
    CameraWidget *arCam = new CameraWidget("camerad", VISION_STREAM_ROAD, true, this);
    split->insertWidget(0, arCam);
  }

  if (getenv("MAP_RENDER_VIEW")) {
    CameraWidget *map_render = new CameraWidget("navd", VISION_STREAM_MAP, false, this);
    split->insertWidget(0, map_render);
  }

  stacked_layout->addWidget(split_wrapper);

  alerts = new OnroadAlerts(this);
  alerts->setAttribute(Qt::WA_TransparentForMouseEvents, true);
  stacked_layout->addWidget(alerts);

  // setup stacking order
  alerts->raise();

  setAttribute(Qt::WA_OpaquePaintEvent);
  QObject::connect(uiState(), &UIState::uiUpdate, this, &OnroadWindow::updateState);
  QObject::connect(uiState(), &UIState::offroadTransition, this, &OnroadWindow::offroadTransition);
  QObject::connect(uiState(), &UIState::primeChanged, this, &OnroadWindow::primeChanged);

  #ifdef DP
  border_indicator = new BorderIndicator;
  #endif
  // rick - read full screen param
  dp_ui_map_full = Params().getBool("dp_ui_map_full");
  dp_ui_map_panel = Params().getBool("dp_ui_map_panel");
}

void OnroadWindow::updateState(const UIState &s) {
  if (!s.scene.started) {
    return;
  }

  if (s.scene.map_on_left || dp_ui_map_full) {
    split->setDirection(QBoxLayout::LeftToRight);
  } else {
    split->setDirection(QBoxLayout::RightToLeft);
  }

  alerts->updateState(s);
  nvg->updateState(s);

  // dp - alka colored border
  const SubMaster &sm = *(s.sm);
  bool alka_active = sm["carControl"].getCarControl().getLatActive() && sm["controlsStateExt"].getControlsStateExt().getAlkaActive();
  QColor bgColor = bg_colors[alka_active && s.status == STATUS_DISENGAGED? STATUS_ALKA : s.status];
  #ifdef DP
  border_indicator->update_states(s);
  if (bg != bgColor || border_indicator->should_repaint()) {
  #else
  if (bg != bgColor) {
  #endif
    // repaint border
    bg = bgColor;
    update();
  }
}

void OnroadWindow::mousePressEvent(QMouseEvent* e) {
#ifdef ENABLE_MAPS
  if (map != nullptr) {
    bool sidebarVisible = geometry().x() > 0;
    bool show_map = !sidebarVisible;
    map->setVisible(show_map && !map->isVisible());
  }
#endif
  // propagation event to parent(HomeWindow)
  QWidget::mousePressEvent(e);
}

void OnroadWindow::createMapWidget() {
#ifdef ENABLE_MAPS
  auto m = new MapPanel(get_mapbox_settings());
  map = m;
  QObject::connect(m, &MapPanel::mapPanelRequested, this, &OnroadWindow::mapPanelRequested);
  QObject::connect(nvg->map_settings_btn, &MapSettingsButton::clicked, m, &MapPanel::toggleMapSettings);
  nvg->map_settings_btn->setEnabled(true);

  if (dp_ui_map_full) {
    m->setFixedWidth(topWidget(this)->width());
  } else {
    m->setFixedWidth(topWidget(this)->width() / 2 - UI_BORDER_SIZE);
  }
  split->insertWidget(0, m);
  // hidden by default, made visible when navRoute is published
  m->setVisible(false);

  if (dp_ui_map_panel) {
    nvg->map_settings_btn->setEnabled(false);
    nvg->map_settings_btn->setVisible(false);
  }
#endif
}

void OnroadWindow::offroadTransition(bool offroad) {
#ifdef ENABLE_MAPS
  if (!offroad) {
    if (map == nullptr && (dp_ui_map_panel || uiState()->hasPrime() || !MAPBOX_TOKEN.isEmpty())) {
      createMapWidget();
    }
  }
#endif
  alerts->clear();
}

void OnroadWindow::primeChanged(bool prime) {
#ifdef ENABLE_MAPS
  if (map && (!dp_ui_map_panel && !prime && MAPBOX_TOKEN.isEmpty())) {
    nvg->map_settings_btn->setEnabled(false);
    nvg->map_settings_btn->setVisible(false);
    map->deleteLater();
    map = nullptr;
  } else if (!map && (dp_ui_map_panel || prime || !MAPBOX_TOKEN.isEmpty())) {
    createMapWidget();
  }
#endif
}

void OnroadWindow::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  #ifdef DP
  p.fillRect(rect(), QColor(bg.red(), bg.green(), bg.blue(), 180));

  border_indicator->paint_bottom(p, QRect(0, height() - UI_BORDER_SIZE, width(), 30));
  border_indicator->paint_left(p, QRect(0, 0, width()*0.2, height()));
  border_indicator->paint_right(p, QRect(width()*0.8, 0, width()*0.2, height()));
  #else
  p.fillRect(rect(), QColor(bg.red(), bg.green(), bg.blue(), 255));
  #endif
}
