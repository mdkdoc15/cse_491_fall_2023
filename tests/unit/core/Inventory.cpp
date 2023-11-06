/**
 * This file is part of the Fall 2023, CSE 491 course project.
 * @brief Unit tests for Inventory
 *
 * @author Yousif Murrani
 **/

// Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

// class project
#include "core/Inventory.hpp"
#include "core/AgentBase.hpp"
#include "core/Item.hpp"

using namespace walle;

TEST_CASE("Inventory Initialization", "[core]"){

	// create a temp agent and get its inventory
	cse491::AgentBase agent(1, "Test Agent");
	Inventory inventory = agent.GetInventory();

	SECTION("Get Agent"){

		// check that the inventorys agent is set correctly
		REQUIRE(inventory.GetAgent() == &agent);
	}
}

TEST_CASE("Add Item to Inventory", "[core]"){

	// create a temp agent and get its inventory
	cse491::AgentBase agent(1, "Test Agent");
	Inventory inventory = agent.GetInventory();

	// create two random items to test on
	std::shared_ptr<walle::Item> item1 = std::make_shared<Item>("sword", 2, 6, 10, 1, 1.0);
	std::shared_ptr<walle::Item> item2 = std::make_shared<Item>("apple", 1, 0, 2, 1, 1.0);

	SECTION("Add Item"){

		// check the default item count
		REQUIRE(inventory.GetItemCount() == 0);

		// checks that adding the items works
		REQUIRE(inventory.AddItem(item1) == true);
		REQUIRE(inventory.AddItem(item2) == true);

		// check the new item count
		REQUIRE(inventory.GetItemCount() == 2);
	}

	// add items to the inventory
	inventory.AddItem(item1);
	inventory.AddItem(item2);

	SECTION("Has Item"){

		// checks that the inventory now has those items
		REQUIRE(inventory.HasItem(item1) == true);
		REQUIRE(inventory.HasItem(item2) == true);
	}

}

TEST_CASE("Drop Item from Inventory", "[core]"){

	// create a temp agent and get its inventory
	cse491::AgentBase agent(1, "Test Agent");
	walle::Inventory inventory = agent.GetInventory();

	// create two random items to test on
	std::shared_ptr<walle::Item> item1 = std::make_shared<Item>("axe", 4, 7, 12, 1, 1.0);
	std::shared_ptr<walle::Item> item2 = std::make_shared<Item>("banana", 1, 1, 1, 1, 1.0);

	inventory.AddItem(item1);
	inventory.AddItem(item2);

	SECTION("Drop Item"){

		// check the item count
		REQUIRE(inventory.GetItemCount() == 2);

		// checks that dropping the items works
		REQUIRE(inventory.DropItem(item1) == true);
		REQUIRE(inventory.DropItem(item2) == true);

		// check the new item count
		REQUIRE(inventory.GetItemCount() == 0);
	}

	// drop the items from the inventory
	inventory.DropItem(item1);
	inventory.DropItem(item2);

	SECTION("Does Not Have Item"){

		// checks that the inventory now does not have those inventory
		REQUIRE(inventory.HasItem(item1) == false);
		REQUIRE(inventory.HasItem(item2) == false);
	}
}

TEST_CASE("Clear the Inventory", "[core]"){

	// create a temp agent and get its inventory
	cse491::AgentBase agent(1, "Test Agent");
	walle::Inventory inventory = agent.GetInventory();

	// create items to test on
    std::shared_ptr<walle::Item> item1 = std::make_shared<Item>("sword", 2, 6, 10, 1, 1.0);
    std::shared_ptr<walle::Item> item2 = std::make_shared<Item>("apple", 1, 0, 2, 1, 1.0);
    std::shared_ptr<walle::Item> item3 = std::make_shared<Item>("axe", 4, 7, 12, 1, 1.0);
    std::shared_ptr<walle::Item> item4 = std::make_shared<Item>("banana", 1, 1, 1, 1, 1.0);

	SECTION("Inventory Empty"){

		// check that the inventory is initially empty
		REQUIRE(inventory.GetItemCount() == 0);
	}

	inventory.AddItem(item1);
	inventory.AddItem(item2);
	inventory.AddItem(item3);
	inventory.AddItem(item4);

	SECTION("Inventory Clear"){

		// check that the items were added
		REQUIRE(inventory.GetItemCount() == 4);

		// clear the inventory and check the item count
		inventory.ClearInventory();
		REQUIRE(inventory.GetItemCount() == 0);
	}
}

TEST_CASE("Transfer Item Between Inventories", "[core]"){

	// create a temp agent and get its inventory
	cse491::AgentBase agent1(1, "Test Agent");
	walle::Inventory inventory1 = agent1.GetInventory();

	// create a second temp agent and get its inventory
	cse491::AgentBase agent2(1, "Test Agent");
	walle::Inventory inventory2 = agent2.GetInventory();

	// create items to test on
	std::shared_ptr<walle::Item> item = std::make_shared<Item>("sword", 2, 6, 10, 1, 1.0);

	inventory1.AddItem(item);

	SECTION("Transfer Item"){

		// transfer item to new inventory and check that it is not in the old one
		REQUIRE(inventory1.TransferItem(item, inventory2) == true);

		REQUIRE(inventory1.HasItem(item) == false);
		REQUIRE(inventory2.HasItem(item) == true);
	}
}

TEST_CASE("Total Inventory Value", "[core]"){

    // create a temp agent and get its inventory
    cse491::AgentBase agent(1, "Test Agent");
    walle::Inventory inventory = agent.GetInventory();

    // create items to test on
    std::shared_ptr<walle::Item> item1 = std::make_shared<Item>("sword", 2, 6, 10, 1, 1.0);
    std::shared_ptr<walle::Item> item2 = std::make_shared<Item>("apple", 1, 0, 2, 5, 1.0);
    std::shared_ptr<walle::Item> item3 = std::make_shared<Item>("axe", 4, 7, 12, 9, 1.0);
    std::shared_ptr<walle::Item> item4 = std::make_shared<Item>("banana", 1, 1, 1, 6, 1.0);

    SECTION("Empty Inventory"){

        // items have not been added yet
        REQUIRE(inventory.CalculateInventoryValue() == 0);
    }

    inventory.AddItem(item1);
    inventory.AddItem(item2);
    inventory.AddItem(item3);
    inventory.AddItem(item4);

    SECTION("Inventory with Items"){

        // items have been added
        REQUIRE(inventory.CalculateInventoryValue() == 21);
    }
}

TEST_CASE("Total Inventory Weight", "[core]"){

    // create a temp agent and get its inventory
    cse491::AgentBase agent(1, "Test Agent");
    walle::Inventory inventory = agent.GetInventory();

    // create items to test on
    std::shared_ptr<walle::Item> item1 = std::make_shared<Item>("sword", 2, 6, 10, 1, 6.0);
    std::shared_ptr<walle::Item> item2 = std::make_shared<Item>("apple", 1, 0, 2, 5, 8.0);
    std::shared_ptr<walle::Item> item3 = std::make_shared<Item>("axe", 4, 7, 12, 9, 2.5);
    std::shared_ptr<walle::Item> item4 = std::make_shared<Item>("banana", 1, 1, 1, 6, 10.0);

    SECTION("Empty Inventory"){

        // items have not been added yet
        REQUIRE(inventory.CalculateInventoryWeight() == 0.0);
    }

    inventory.AddItem(item1);
    inventory.AddItem(item2);
    inventory.AddItem(item3);
    inventory.AddItem(item4);

    SECTION("Inventory with Items"){

        // items have been added
        REQUIRE(inventory.CalculateInventoryWeight() == 26.5);
    }
}

TEST_CASE("Inventory Full/Empty"){

    // create a temp agent and get its inventory
    cse491::AgentBase agent(1, "Test Agent");
    walle::Inventory inventory = agent.GetInventory();

    // create items to test on
    std::shared_ptr<walle::Item> item1 = std::make_shared<Item>("sword", 2, 6, 10, 1, 6.0);
    std::shared_ptr<walle::Item> item2 = std::make_shared<Item>("apple", 1, 0, 2, 5, 8.0);
    std::shared_ptr<walle::Item> item3 = std::make_shared<Item>("axe", 4, 7, 12, 9, 2.5);
    std::shared_ptr<walle::Item> item4 = std::make_shared<Item>("banana", 1, 1, 1, 6, 10.0);
    std::shared_ptr<walle::Item> item5 = std::make_shared<Item>("sword", 2, 6, 10, 1, 6.0);
    std::shared_ptr<walle::Item> item6 = std::make_shared<Item>("apple", 1, 0, 2, 5, 8.0);
    std::shared_ptr<walle::Item> item7 = std::make_shared<Item>("axe", 4, 7, 12, 9, 2.5);
    std::shared_ptr<walle::Item> item8 = std::make_shared<Item>("banana", 1, 1, 1, 6, 10.0);
    std::shared_ptr<walle::Item> item9 = std::make_shared<Item>("sword", 2, 6, 10, 1, 6.0);
    std::shared_ptr<walle::Item> item10 = std::make_shared<Item>("apple", 1, 0, 2, 5, 8.0);

    SECTION("Inventory Empty"){

        // checks that the inventory is empty
        REQUIRE(inventory.IsEmpty() == true);
        REQUIRE(inventory.IsFull() == false);
    }

    inventory.AddItem(item1);
    inventory.AddItem(item2);
    inventory.AddItem(item3);
    inventory.AddItem(item4);
    inventory.AddItem(item5);
    inventory.AddItem(item6);
    inventory.AddItem(item7);
    inventory.AddItem(item8);
    inventory.AddItem(item9);
    inventory.AddItem(item10);

    SECTION("Inventory Full"){

        // checks that the inventory is full
        REQUIRE(inventory.IsEmpty() == false);
        REQUIRE(inventory.IsFull() == true);
    }
}