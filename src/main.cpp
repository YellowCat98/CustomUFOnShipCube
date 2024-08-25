#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(GJBaseGameLayer) {
	void playerWillSwitchMode(PlayerObject* p0, GameObject* p1) {
		GJBaseGameLayer::playerWillSwitchMode(p0, p1);
			if (p1->m_objectType == GameObjectType::ShipPortal) {
				p0->updatePlayerFrame(Mod::get()->getSettingValue<int64_t>("ship-cube"));
			} else if (p1->m_objectType == GameObjectType::UfoPortal) {
				p0->updatePlayerFrame(Mod::get()->getSettingValue<int64_t>("ufo-cube"));
			} else {
				p0->updatePlayerFrame(GameManager::get()->m_playerFrame.value());
			}
	}
};