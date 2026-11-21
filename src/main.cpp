
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto menu = this->getChildByID("bottom-menu");
        if (!menu)
            return true;

        auto sprite = ButtonSprite::create("Auto Deco AI");

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(MyMenuLayer::onAutoDecoAI)
        );

        button->setID("auto-deco-ai-button"_spr);
        menu->addChild(button);
        menu->updateLayout();

        return true;
    }

    void onAutoDecoAI(CCObject*) {
        FLAlertLayer::create(
            "Auto Deco AI",
            "Welcome! AI Style Transfer is coming soon.",
            "OK"
        )->show();
    }
};
