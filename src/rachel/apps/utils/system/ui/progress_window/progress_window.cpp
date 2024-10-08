/**
 * @file progress_window.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "progress_window.h"
#include "../../../../../hal/hal.h"
#include "../common/data_structs.hpp"
#include "../../assets/theme/theme.h"

void SYSTEM::UI::ProgressWindow(std::string title, uint8_t progress, bool lightMode, bool useCanvas)
{
    lgfx::LGFXBase* display = nullptr;
    if (useCanvas)
        display = HAL::GetCanvas();
    else
        display = HAL::GetDisplay();

    uint32_t color_light = THEME_COLOR_LIGHT;
    uint32_t color_dark = THEME_COLOR_DARK;
    if (lightMode)
        std::swap(color_light, color_dark);

    // Clear screen
    display->fillScreen(color_light);

    // Draw title
    display->setTextColor(color_dark, color_light);
    display->drawCenterString(title.c_str(), display->width() / 2, display->height() / 4);

    // Draw progress bar base
    BasicShape_t progress_bar;
    progress_bar.width = display->width() * 8 / 10;
    progress_bar.height = display->height() / 4;
    progress_bar.x = (display->width() - progress_bar.width) / 2;
    progress_bar.y = display->height() / 2;
    display->fillSmoothRoundRect(progress_bar.x, progress_bar.y, progress_bar.width, progress_bar.height, 10, color_dark);

    // Draw progress bar
    if (progress > 100)
        progress = 100;
    display->fillSmoothRoundRect(progress_bar.x + 4,
                                 progress_bar.y + 4,
                                 (progress_bar.width - 8) * progress / 100,
                                 progress_bar.height - 8,
                                 10,
                                 color_light);

    // printf("progress x:%d y:%d w:%d h:%d\n", progress_bar.x, progress_bar.y, progress_bar.width, progress_bar.height);
}
