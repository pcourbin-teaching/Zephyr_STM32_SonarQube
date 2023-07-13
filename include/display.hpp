#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <drivers/display.h>
#include <lvgl.h>
#include <string.h>

#define DISPLAY_DEV_NAME DT_LABEL(DT_INST(0, ilitek_ili9340))

#define TEXT_MAX_SIZE 2000
#define CHART_DEFAULT_WIDTH 230
#define CHART_DEFAULT_HEIGHT 100
#define CHART_DEFAULT_NUMBER_POINTS 100
#define CHART_DEFAULT_PRIMARY_Y_MIN 20
#define CHART_DEFAULT_PRIMARY_Y_MAX 35
#define CHART_DEFAULT_SECONDARY_Y_MIN 0
#define CHART_DEFAULT_SECONDARY_Y_MAX 100
#define CHART_DEFAULT_TEMPERATURE_COLOR LV_COLOR_GREEN
#define CHART_DEFAULT_HUMIDITY_COLOR LV_COLOR_BLUE

class Display
{
public:
  const struct device *dev;
  lv_obj_t *logo = NULL;
  lv_obj_t *text = NULL;
  char text_value[TEXT_MAX_SIZE] = "";
  unsigned char text_nb = 0;
  unsigned char text_nb_max = 1;
  lv_obj_t *chart = NULL;
  lv_chart_series_t *serie_temperature = NULL;
  lv_chart_series_t *serie_humidity = NULL;

  void task_handler();

  void lv_create_logo();
  void lv_create_text();
  void lv_create_chart();
  void init(bool with_chart = true);

  void chart_add_temperature(long value);
  void chart_add_humidity(long value);

  void text_add(char *text_to_add);
  void text_clear();
};

#endif