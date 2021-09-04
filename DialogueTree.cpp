//
// Created by Maxime Blanc on 04/09/2021.
//

#include "DialogueTree.h"
#include <iostream>

DialogueOption::DialogueOption(std::string pText, int pReturnCode, DialogueNode *pNextNode) {
	text = pText;
	returnCode = pReturnCode;
	nextNode = pNextNode;
}

DialogueNode::DialogueNode(std::string pText) {
	text = pText;
}

void DialogueTree::init() {
	auto *node0 = new DialogueNode("Hello brave warrior !");
	auto *node1 = new DialogueNode("I don't want to talk to you.");
	auto *node2 = new DialogueNode("I have a quest for you!");
	auto *node3 = new DialogueNode("Yes you will get 5 gold you greedy swine.");
	auto *node4 = new DialogueNode("Collect 10 dandelions");

	node0->options.emplace_back("Sup noob!", 0, node1);
	node0->options.emplace_back(std::string("Hello strange voice!"), 0, node2);
	nodes.push_back(node0);

	node1->options.emplace_back("Awww", 0, nullptr);
	nodes.push_back(node1);

	node2->options.emplace_back("K bye.", 0, nullptr);
	node2->options.emplace_back("What is it?", 0, node4);
	node2->options.emplace_back("What's the pay?", 0, node3);
	nodes.push_back(node2);

	node3->options.emplace_back("Ok what is it?", 0, node4);
	node3->options.emplace_back("That sucks I'm out.", 0, nullptr);
	nodes.push_back(node3);

	node4->options.emplace_back("Let's do it!", 1, nullptr);
	node4->options.emplace_back("No way!", 0, nullptr);
	nodes.push_back(node4);
}

void DialogueTree::destroyTree() {
	for (int i = 0; i < nodes.size(); i++) {
		delete nodes[i];
	}

	nodes.clear();
}

int DialogueTree::performDialogue() {
	if (nodes.empty()) return -1;

	DialogueNode *currentNode = nodes.front();

	while (true) {
		printf("\033[1;34m%s\n\n\033[0m", currentNode->text.c_str());

		for (int i = 0; i < currentNode->options.size(); i++) {
			printf("%d. %s\n", i + 1, currentNode->options[i].text.c_str());
		}

		printf(("\nYour answer: "));

		int input;
		std::cin >> input;
		input --;

		if (input < 0 || input > currentNode->options.size()) {
			printf("Invalid input");
			return -1;
		} else {
			// Check for end of conversation
			if (currentNode->options[input].nextNode == nullptr) return currentNode->options[input].returnCode;

			currentNode = currentNode->options[input].nextNode;
		}

		printf("\n");
	}

	return 0;
}
