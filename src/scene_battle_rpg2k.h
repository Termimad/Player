/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SCENE_BATTLE_RPG2K_H_
#define _SCENE_BATTLE_RPG2K_H_

// Headers
#include "scene_battle.h"
#include "game_enemy.h"

#include "window_command.h"
#include "window_battlemessage.h"

/**
 * Scene_Battle class.
 * Manages the battles.
 */
class Scene_Battle_Rpg2k : public Scene_Battle {

public:
	Scene_Battle_Rpg2k();
	~Scene_Battle_Rpg2k() override;

	void Update() override;

protected:
	void SetState(State new_state) override;

	void NextTurn();

	void CreateUi() override;

	void CreateBattleTargetWindow();
	void CreateBattleCommandWindow();

	bool CheckWin();
	bool CheckLose();
	bool CheckAbort();
	bool CheckFlee();
	bool CheckResultConditions();

	void RefreshCommandWindow();

	void ProcessActions() override;

	bool ProcessBattleAction(Game_BattleAlgorithm::AlgorithmBase* action);
	void ProcessInput() override;

	void OptionSelected();
	void CommandSelected();

	void Escape();

	void SelectNextActor();
	void SelectPreviousActor();

	void CreateExecutionOrder();
	void CreateEnemyActions();

	bool DisplayMonstersInMessageWindow();

	std::unique_ptr<Window_BattleMessage> battle_message_window;
	std::vector<std::string> battle_result_messages;
	std::vector<std::string>::iterator battle_result_messages_it;
	std::vector<std::shared_ptr<Game_Enemy> >::const_iterator enemy_iterator;
	int battle_action_wait;
	int battle_action_state;

	int select_target_flash_count = 0;
	bool encounter_message_first_monster = true;
	int encounter_message_sleep_until = -1;

	bool begin_escape = true;
	bool escape_success = false;
	int escape_counter = 0;

	bool message_box_got_visible = false;
};

#endif
