#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

bool isCube(PlayerObject* player) {
	return !player->m_isShip && !player->m_isBall && !player->m_isBird && !player->m_isDart && !player->m_isRobot && !player->m_isSpider && !player->m_isSwing;
}

class $modify(GJBaseGameLayerHook, GJBaseGameLayer) {
	void visit() {
		GJBaseGameLayer::visit();
		if (m_player1->m_isBird) {
			m_player1->updatePlayerFrame(Mod::get()->getSettingValue<int64_t>("ufo-cube"));
		} else if (m_player1->m_isShip) {
			m_player1->updatePlayerFrame(Mod::get()->getSettingValue<int64_t>("ship-cube"));
		} else if (isCube(m_player1)) {
			m_player1->updatePlayerFrame(GameManager::get()->m_playerFrame.value());
		}
	}
};