#include "DialogueTree.h"

int main() {
	DialogueTree tree;

	tree.init();

	int res = tree.performDialogue();

	if (res == 1) {
		printf("\033[1;332mYou got the quest!\033[0m");
	}

	tree.destroyTree();

	getchar();
	return 0;
}
