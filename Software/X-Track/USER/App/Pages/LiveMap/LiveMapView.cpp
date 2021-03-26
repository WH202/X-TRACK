#include "LiveMapView.h"
#include <stdarg.h>
#include <stdio.h>

#define MAP_TILE_SIZE 256

void LiveMapView::Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_cont_create(par, NULL);
    lv_obj_set_size(cont, MAP_TILE_SIZE * 3, MAP_TILE_SIZE * 3);
    lv_obj_set_drag(cont, true);
    lv_obj_align(cont, NULL, LV_ALIGN_CENTER, 0, 0);
    ui.map.cont = cont;

    for (int i = 0; i < ARRAY_SIZE(ui.map.imgMap); i++)
    {
        lv_obj_t* img = lv_img_create(cont, NULL);
        lv_img_set_auto_size(img, false);
        lv_obj_set_pos(img, i % 3 * MAP_TILE_SIZE, i / 3 * MAP_TILE_SIZE);
        lv_obj_set_size(img, MAP_TILE_SIZE, MAP_TILE_SIZE);
        lv_obj_set_drag_parent(img, true);

        ui.map.imgMap[i] = img;
    }

    lv_obj_t* img = lv_img_create(cont, NULL);
    lv_img_set_src(img, Resource.GetImage("img_src_gps_arrow"));
    ui.map.imgArrow = img;

    lv_obj_t* slider = lv_slider_create(par, NULL);
    lv_obj_set_size(slider, 5, 100);
    lv_slider_set_range(slider, 3, 15);
    lv_obj_align(slider, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0);
    ui.sliderLevel = slider;

    lv_obj_t* label = lv_label_create(par, NULL);
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
    lv_obj_set_auto_realign(label, true);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_20);
    lv_label_set_text(label, "");
    lv_obj_set_hidden(label, true);
    ui.labelInfo = label;

    lv_obj_t* btn = lv_btn_create(par, NULL);
    lv_obj_set_size(btn, 20, 20);
    lv_obj_set_style_local_value_str(btn, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "i");
    lv_obj_align(btn, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 5);
    ui.btnInfo = btn;

    btn = lv_btn_create(par, NULL);
    lv_obj_set_size(btn, 30, 20);
    lv_obj_set_style_local_value_str(btn, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_SYMBOL_DOWN);
    lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -5, -5);
    ui.btnBack = btn;
}