/**
 * @file app_screencast.h
 * @author Forairaaaaa
 * @brief Ref: https://github.com/lovyan03/ESP32_ScreenShotReceiver
 * @version 0.1
 * @date 2023-11-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <mooncake.h>
#include "assets/icon_app_screen_cast.hpp"

namespace MOONCAKE::APPS
{
    /**
     * @brief Screencast
     *
     */
    class AppScreencast : public APP_BASE
    {
    public:
        void onCreate() override;
        void onResume() override;
        void onRunning() override;
        void onDestroy() override;
    };

    class AppScreencast_Packer : public APP_PACKER_BASE
    {
        std::string getAppName() override { return "Screen Cast"; }
        void* getAppIcon() override { return (void*)image_data_icon_app_screen_cast; }
        void* newApp() override { return new AppScreencast; }
        void deleteApp(void* app) override { delete (AppScreencast*)app; }
    };
} // namespace MOONCAKE::APPS
