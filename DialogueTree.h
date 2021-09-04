//
// Created by Maxime Blanc on 04/09/2021.
//

#pragma once

#include <vector>
#include <string>

class DialogueOption;
class DialogueNode;

class DialogueTree {
public:
	void init();
	void destroyTree();
	int performDialogue();
private:
	std::vector<DialogueNode *> nodes;
};

class DialogueNode {
public:
	DialogueNode(std::string pText);
public:
	std::string text;
	std::vector<DialogueOption> options;
};

class DialogueOption {
public:
	DialogueOption(std::string pText, int pReturnCode, DialogueNode *pNextNode);
public:
	std::string text;
	int returnCode;
	DialogueNode *nextNode;
};
