#include <iostream>
#include <string>
#define MAX_ELEMENTS 5 //������������� ������������ ���������� ��������� � �����
class word {
public:
	std::string s; //������� �����(������ ��������)
};
class sentence {
	word* w; //������� �����������(�����)
	sentence* next; //��������� �� ��������� ������� �����������
public:
	void start(sentence*); //�������� ������� ������ ������ � ������������
	sentence* makeEmpty(sentence*); //�������� ������� �������� �����������
	bool isEmpty(sentence*); //�������� ������� �������� ����������� �� �������
	bool isEnd(sentence*); //�������� �������, ������� ��������� ��������� �� ��������� � �����
	sentence* movePtr(sentence*); //�������� ������� ����������� ��������� �� ��������� �������
	void checkElementAfterPtr(sentence*); //�������� ������� ������ �������� ����� ���������
	void deleteAfterPtr(sentence*); //�������� ������� �������� �������� ����� ���������
	void changeValueAfterPtr(sentence*); //�������� ������� ��������� �������� ����� ���������
	sentence* push_backAfterPtr(sentence*, sentence*); //�������� ������� ���������� �������� ����� ���������
	sentence* addElementFromBufer(sentence*, word*); //�������� ������� ���������� �������� �� ������
	int size(sentence*); //�������� �������, ����������� ������ �����������
	word* retWord(sentence*); //�������� �������, ������������ �����
	void output(sentence*, sentence*); //�������� ������� ������ �����������
	friend void simpleSentenceOutput(sentence*); //�������� ������� ������� �����������
	friend sentence* returnNewSentence(sentence*); //�������� ������� ��������� ����� ������ ��� �����������
};

class text {
	sentence* snt; //������� ������(�����������)
	text* next; //��������� �� ��������� ������� ������
	text* prev; //��������� �� ���������� ������� �������
public:
	void start(text*); //�������� ������� ������ ������ � �������
	bool isEmpty(text*); //�������� ������� �������� ������ �� �������
	bool isStart(text*); //�������� �������, ������� ��������� ��������� �� ��������� � ������
	bool isEnd(text*); //�������� �������, ������� ��������� ��������� �� ��������� � �����
	text* movePtrNext(text*); //�������� ������� ����������� ��������� �� ��������� �������
	text* movePtrPrev(text*); //�������� ������� ����������� ��������� �� ���������� �������
	text* toEnd(text*); //�������� �������, ������� ���������� ��������� � �����
	text* makeEmpty(text*); //�������� ������� �������� ������
	text* push_back_after_ptr(text*, text*); //�������� ������� ���������� �������� ����� ���������
	text* push_back_before_ptr(text*, text*); //�������� ������� ���������� �������� �� ���������
	void showElementValueAfterPtr(text*); //������ ������� ������ �������� ����� ���������
	void showElementValueBeforePtr(text*); //������ ������� ������ �������� �� ���������
	void deleteAfterPtr(text*); //�������� ������� �������� �������� ����� ���������
	text* deleteBeforePtr(text*, text*); //�������� ������� �������� �������� �� ���������
	void changeElementAfterPtr(text*); //�������� ������� ��������� �������� ����� ���������
	text* changeElementBeforePtr(text*); //�������� ������� ��������� �������� �� ���������
	sentence* getSentence(text*); //�������� �������, ������� ���������� �����������
	int size(text*); //�������� �������, ������� ����������� ������ ������
	text* addElementAfterPtr(text*, sentence*, text*); //�������� ������� ���������� �������� �� ������ ����� ���������
	text* addElementBeforePtr(text*, sentence*, text*, bool&); //�������� ������� ���������� �������� �� ������ �� ���������
	void output(text*, text*); //�������� ������� ������ ������
	friend void simpleTextOutput(text*); //�������� ������� ������ ������
	friend text* makeNull(text*); //�������� ������� ��������� ������
};

class stack {
	text* txt; //������� �����(�����)
	stack* next; //��������� �� ��������� ������� �����
	int count; //���������� ��������� � �����
public:
	stack() { //����������� ����� �� ���������
		count = 0;
	}
	void start(stack*); //�������� ������� ������ ������ �� ������
	stack* makeEmpty(stack*); //������� ������� �������� �����
	bool isEmpty(stack*); //�������� �������, ������� ��������� ���� �� ����
	void printHeadValue(stack*); //�������� �������, ������� �������� �������� ������� �����
	stack* deleteHead(stack*); //�������� �������, ������� ������� �������� ������� �����
	stack* takeHead(stack*); //�������� �������, ������� �������� �������� ������� ����� � �����
	stack* setText(stack*, text*);
	stack* changeHeadValue(stack*); //�������� �������, ������� �������� �������� ������� �����
	stack* push_back(stack*); //�������� ������� ���������� ��������
	stack* putBufer(stack*, stack*); //�������� ������� ���������� �������� �� ������
	stack* makeTxtNull(stack*); //�������� ������� ��������� ������ � �����
	stack* retNextElement(stack*); //������� �������, ������� ���������� ��������� ������� �����
	text* getText(stack*); //�������� �������, ������� ���������� ����� �����
	void output(stack*); //�������� ������� ������ �����
	void incCount() { //���������� ���������� ��������� � �����
		count++;
	}
	void dicCount() { //���������� ���������� ��������� � �����
		count--;
	}
	int getCount() { //����������� ���������� ��������� � �����
		return count;
	}
	void changeCount(int count) { //��������� ���������� ��������� �����
		this->count = count;
	}
};

int sentence::size(sentence* l) { //���������� ���������� ��������� �����������
	int size = 0;
	while (l != NULL) {
		++size;
		l = l->next;
	}
	return size;
}
void deleteText(text* root) { //������� �������� ������
	while (root != NULL) {
		auto tmp = root;
		root = root->movePtrNext(root);
		tmp->makeEmpty(tmp); //������� �������� �����������
		delete tmp;
	}
}

void deleteStack(stack* st) { //������� �������� �����
	while (st != NULL) {
		auto tmp = st->getText(st);
		st = st->retNextElement(st);
		deleteText(tmp); //������� �������� ������
		delete tmp;
	}
}
int getPointerPos(sentence* l, sentence* root) { //���������� ������� �������� ��������� �����������
	return root->size(root) - l->size(l);
}
void sentence::start(sentence* l) { //������ ������ �����������
	l = NULL;
	std::cout << "You have started working with sentence list\n";
}
bool sentence::isEmpty(sentence* l) { //�������� �� ������� �����������
	return l == NULL;
}
sentence* sentence::makeEmpty(sentence* root) { //������� �������� �� ������ �����������
	while (root != NULL) {
		delete root->w;
		root = root->next;
	}
	root = NULL;
	return root;
}
bool sentence::isEnd(sentence* l) { //�������, ������� ��������� ��������� �� ������� ��������� � �����
	return l->next == NULL;
}
sentence* sentence::movePtr(sentence* l) { //������� ����������� �������� ��������� �� ��������� ������� (�����������)
	return l = l->next;
}
void sentence::checkElementAfterPtr(sentence* l) { //������� ������ �������� ����� �������� ��������� (�����������)
	std::cout << "element after pointer >> " << l->next->w->s << "\n";
}
void sentence::deleteAfterPtr(sentence* l) { //������� �������� �������� ����������� ����� ���������
	sentence* tmp = new(std::nothrow) sentence;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated!\n";
		exit(-1);
	}
	tmp = l->next;
	l->next = l->next->next;
	delete tmp;
}
sentence* returnNewSentence(sentence* root) { //�������, ������� ���������� ����������� �� ������ ���������� ������
	sentence* newroot = new(std::nothrow) sentence;
	if (!newroot) {
		std::cout << "Error. Memocy cannot be allocated\n";
		exit(-1);
	}
	sentence* tcur = newroot;
	while (root)
	{
		tcur->w = root->w;
		root = root->next;
		tcur->next = new(std::nothrow) sentence;
		if (!tcur->next) {
			std::cout << "Error. Memory cannot be allocated\n";
			exit(1);
		}
		if (root)
			tcur = tcur->next;
	}
	delete tcur->next;
	tcur->next = NULL;
	return newroot;
}
void sentence::changeValueAfterPtr(sentence* l) { //��������� �������� ����������� ����� �������� ���������
	if (l->next != NULL) {
		std::cout << "Enter the new string: ";
		std::cin >> l->next->w->s;
	}
	else std::cout << "You can`t change element out of range!\n";
}
sentence* sentence::push_backAfterPtr(sentence* l, sentence* root) { //������� ���������� �������� ����� ���������
	sentence* tmp = new(std::nothrow) sentence;
	if (tmp == NULL) {
		std::cout << "Error. memory cannot be allocated\n";
		exit(-1);
	}
	word* wrd = new(std::nothrow) word;
	if (wrd == NULL) {
		std::cout << "Error. memory cannot be allocated\n";
		exit(-1);
	}
	std::cout << "enter the string: ";
	std::cin >> wrd->s;
	tmp->w = wrd;
	int pointerPos = getPointerPos(l, root); //��������� � ��������� ������� �������� ���������
	l = root;
	for (int i = 0; i < pointerPos; ++i) {
		l = l->next;
	}
	if (!l->size(l)) {
		tmp->next = NULL;
		return tmp;
	}
	else {
		tmp->next = l->next;
		l->next = tmp;
		l = root;
		return l;
	}
}
void sentence::output(sentence* l, sentence* root) { //������� ������ �����������
	sentence* tmp = new(std::nothrow) sentence;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = root;
	int ptrPos = getPointerPos(l, root); //��������� � ��������� ������� �������� ���������
	int count = 0;
	while (root != NULL) {
		word* var = root->w;
		count == ptrPos ? std::cout << "|" << "\033[34m" << var->s << "\033[0m" << "|" : std::cout << "|" << var->s << "|";
		root = root->next;
		count++;
	}
	std::cout << std::endl;
	root = tmp;
}
word* sentence::retWord(sentence* s) { //���������� �����
	word* wr = new(std::nothrow) word;
	if (wr == NULL) {
		std::cout << "Error. Memory cannto be allocated\n";
		exit(-1);
	}
	return wr = s->w;
}
sentence* sentence::addElementFromBufer(sentence* l, word* bufer) { //���������� �������� �� ������
	sentence* tmp = new(std::nothrow) sentence;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	word* wr = new(std::nothrow) word;
	if (wr == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	wr->s = bufer->s;
	tmp->w = wr;
	if (l != NULL) {
		if (l->isEnd(l)) {
			l->next = tmp;
			tmp->next = NULL;
			return l;
		}
		else {
			tmp->next = l->next;
			l->next = tmp;
			return l;
		}
	}
	else {
		tmp->next = NULL;
		return tmp;
	}
}
text* makeNull(text* txt) { //��������� ������
	txt->snt = NULL;
	return txt;
}
sentence* menuForSentence(sentence* snt) { //���� �����������
	sentence* l = NULL;
	sentence* root = l;
	word* bufer = NULL;
	int task, ptrPos;
	bool isCreated = false; //���� ������ ������ � ������������
	text* txt = new(std::nothrow) text;
	if (txt == NULL) {
		std::cout << "Error. Memory cannot be allocted\n";
		exit(-1);
	}
	if (!snt->isEmpty(snt)) //�������� �� ������� �����������
		l = root = snt;
	while (1) {
		if (bufer != NULL) {
			std::cout << "\033[33mbufer >> " << bufer->s; std::cout << "\033[0m\n";
		}
		if (!l->isEmpty(l))
			l->output(l, root);
		else std::cout << "\033[33msentence list is empty\033[0m\n";
		std::cout << "choose what to do with sentance (L1):\n\n";
		std::cout << "choose '1' to start working with list\n";
		std::cout << "choose '2' to make list empty\n";
		std::cout << "choose '3' to check if list is empty\n";
		std::cout << "choose '4' to set pointer to start\n";
		std::cout << "choose '5' to check if pointer is located at the end\n";
		std::cout << "choose '6' to move pointer to the next element\n";
		std::cout << "choose '7' to print element after pointer\n";
		std::cout << "choose '8' to delete element after pointer\n";
		std::cout << "choose '9' to take element after pointer\n";
		std::cout << "choose '10' to change list value after pointer\n";
		std::cout << "choose '11' to add an element after pointer\n";
		std::cout << "choose '12' to print list\n";
		std::cout << "choose '13' to end working with sentence list\n";
		std::cout << ">> ";
		std::cin >> task;
		system("cls");
		switch (task) {
		case 1:
			if (!isCreated) { //�������� �� ������ ������ � ������������
				l->start(l);
				isCreated = true; //������ ����
			}
			else {
				std::cout << "\033[33mYou already have started working with sentence list\033[0m\n";
			}
			break;
		case 2:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (!l->isEmpty(l)) { //�������� �� ������� �����������
					root = l->makeEmpty(root); //�������� �����������
					l = root;

				}
				else {
					std::cout << "\033[33msentence list is already empty\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 3:
			if (isCreated) { //�������� �� ������ ������ � ������������
				l->isEmpty(l) == 1 ? std::cout << "\033[33msentence list is empty\033[0m\n" : std::cout << "\033[33msentence list is not empty\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 4:
			if (isCreated) { //�������� �� ������ ������ � ������������
				l = root;
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 5:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (!l->isEmpty(l))
					l->isEnd(l) == 1 ? std::cout << "\033[33mpointer is located at the end\033[0m\n" : std::cout << "\033[33mpointer is not at the end\033[0m\n";
				else std::cout << "\033[33msentence list is empty\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 6:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (!l->isEmpty(l)) { //�������� �� ������� �����������
					if (l->isEnd(l)) { //�������� ��������� �� ������� ��������� � ����� �����������
						std::cout << "\033[33mpointer is located at the end. Do you want to set it to the start? Type y/n\033[0m\n << ";
						char answ;
						std::cin >> answ;
						if (answ == 'y')
							l = root; //����������� �������� ��������� � ������, ���� ������������ ��������
					}
					else {
						l = l->movePtr(l); //����������� �������� ��������� ������
					}
				}
				else std::cout << "\033[33mcant move ptr in empty list\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 7:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (!l->isEmpty(l) && !l->isEnd(l)) {
					l->checkElementAfterPtr(l);
				}
				else {
					std::cout << "\033[33mYou can`t check element that does not exist\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 8:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (!l->isEmpty(l)) {
					if (!l->isEnd(l))
						l->deleteAfterPtr(l);
					else std::cout << "\033[33mpointer is at the end. Cant delete non existence element\033[0m\n";
				}
				else std::cout << "\033[33myou can`t delete in empty sentence list!\033[0m\n";
			}
			else
				std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 9:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (!l->isEmpty(l) && !l->isEnd(l)) { //�������� �� ������� �����������
					bufer = l->retWord(l->movePtr(l));
					l->deleteAfterPtr(l);
				}
				else
					std::cout << "\033[33mYou cant take non existing element\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 10:
			if (isCreated) { //�������� �� ������ ������ � �����������
				if (!l->isEmpty(l) && !l->isEnd(l))
					l->changeValueAfterPtr(l);
				else std::cout << "\033[33mcannot change non existing elements\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 11:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (bufer != NULL) {
					std::cout << "\033[33mbufer is not empty. Would you like to add element from bufer? Press y/n\033[0m\n";
					char s;
					std::cin >> s;
					if (s == 'y') {
						l == NULL ? root = l->addElementFromBufer(l, bufer), l = root : l = l->addElementFromBufer(l, bufer);
					}
					else {
						ptrPos = getPointerPos(l, root);
						root = l->push_backAfterPtr(l, root);
						l = root;
						for (int i = 0; i < ptrPos; ++i) {
							l = l->movePtr(l);
						}
					}
				}
				else {
					ptrPos = getPointerPos(l, root);
					root = l->push_backAfterPtr(l, root);
					l = root;
					for (int i = 0; i < ptrPos; ++i) {
						l = l->movePtr(l);
					}
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 12:
			if (isCreated) { //�������� �� ������ ������ � ������������
				if (bufer != NULL) {
					std::cout << "\033[33mbufer >> " << bufer->s; std::cout << "\033[0m\n";
				}
				l->output(l, root); //����� ��������� �����������
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 13:
			if (isCreated) { //�������� �� ������ ������ � ������������
				l = root;
				if (!l->isEmpty(l)) { //�������� �� ������� �����������
					return l;
				}
				else {
					l = root = root->makeEmpty(root); //�������� �����������
					return l;
				}
			}
			else std::cout << "you didn`t start working with sentence\n";
			break;
		default:
			std::cout << "\033[33mwrong command\033[0m\n";
			break;
		}
	}
}
void text::start(text* l) { //������� ������ ������ � �������
	l = NULL;
	std::cout << "You have started to work with list\n\n";
}
bool text::isEmpty(text* l) { //�������, ������� ��������� ���� �� �����
	return l == NULL;
}
text* text::makeEmpty(text* root) { //������� �������� ������
	root = NULL;
	return root;
}
int text::size(text* l) { //������������� ���������� ��������� ������
	int size = 0;
	while (l != NULL) {
		++size;
		l = l->next;
	}
	return size;
}
int getPointerPos(text* l, text* root) { //���������� ������� �������� ��������� ������
	return root->size(root) - l->size(l);
}
bool text::isStart(text* l) { //������� �������� ��������� �� ������� ��������� � ������ ������
	return l->prev == NULL;
}
bool text::isEnd(text* l) {  //������� �������� ��������� �� ������� ��������� � ����� ������
	return l->next == NULL;
}
text* text::movePtrNext(text* l) { //����������� �������� ��������� �� ��������� �������
	return l = l->next;
}
text* text::movePtrPrev(text* l) { //����������� �������� ��������� �� ���������� �������
	return l = l->prev;
}
void text::showElementValueAfterPtr(text* l) { //����� �������� ������ ����� ���������
	sentence* snt = new(std::nothrow) sentence;
	snt = l->next->snt;
	std::cout << "element after pointer >> "; simpleSentenceOutput(snt); std::cout << std::endl;
}
void text::showElementValueBeforePtr(text* l) { //����� �������� ������ �� ���������
	sentence* snt = new(std::nothrow) sentence;
	snt = l->prev->snt;
	std::cout << "element before pointer >> "; simpleSentenceOutput(snt); std::cout << std::endl;
}
void text::deleteAfterPtr(text* l) { //�������� �������� ������ ����� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = l;
	l = l->next;
	if (l->next != NULL) {
		l = l->next;
		l->prev = tmp;
		tmp = l;
		l = l->prev;
		l->next = tmp;
	}
	else {
		l = l->prev;
		l->next = l->next->next;
	}
}
text* text::deleteBeforePtr(text* l, text* root) { //�������� �������� ������ �� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = l;
	l = l->prev;
	if (l->prev != NULL) {
		l = l->prev;
		l->next = tmp;
		tmp = l;
		l = l->next;
		l->prev = tmp;
		l = root;
	}
	else {
		l = l->next;
		l->prev = l->prev->prev;
	}
	return l;
}
void text::changeElementAfterPtr(text* l) { //��������� �������� ������ ����� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = (l->next)->next;
	l->next->snt = menuForSentence(l->getSentence(l->next)); //����� ���� �����������
	if (l->next != NULL) {
		(l->next)->prev = l;
		(l->next)->next = tmp;
	}
	else {
		text* var = new(std::nothrow) text;
		if (var == NULL) {
			std::cout << "Error. Memory cannot be allocated\n";
			exit(-1);
		}
		var->snt = NULL;
		var->prev = l;
		var->next = NULL;
		l->next = var;
	}

}
text* text::changeElementBeforePtr(text* l) { //��������� �������� ������ ����� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = (l->prev)->prev;
	l->prev->snt = menuForSentence(l->getSentence(l->prev)); //����� ���� �����������
	text* var = new(std::nothrow) text;
	if (var == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	if (l->prev != NULL) {
		(l->prev)->next = l;
		(l->prev)->prev = tmp;
		l = l->prev;
		l = l->prev;
	}
	else {
		var->snt = NULL;
		var->next = l;
		var->prev = NULL;
		l->prev = var;
		l = l->prev;
		return l;
	}

}
sentence* text::getSentence(text* l) {
	return l->snt;
}
text* text::toEnd(text* l) { //����������� ��������� � ����� ������
	while (l->next != NULL) {
		l = l->next;
	}
	return l;
}
text* text::push_back_after_ptr(text* l, text* root) { //���������� �������� ����� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	text* var = new(std::nothrow) text;
	if (var == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp->snt = menuForSentence(NULL); //����� ���� �����������
	if (tmp == NULL) {
		if (!l->isEmpty(l)) {
			var->snt = NULL;
			var->next = l->next;
			var->prev = l;
			l->next = var;
			l = l->next;
			if (l->next != NULL)
				(l->next)->prev = var;
			l = root;
			return l;
		}
		else {
			var->snt = NULL;
			var->prev = NULL;
			var->next = NULL;
			return l = var;
		}
	}
	if (!l->size(l)) {
		tmp->next = NULL;
		tmp->prev = NULL;
		return tmp;
	}
	else {
		tmp->next = l->next;
		tmp->prev = l;
		l->next = tmp;
		l = l->next;
		if (l->next != NULL)
			(l->next)->prev = tmp;
		l = root;
		return l;
	}
}
text* text::push_back_before_ptr(text* l, text* root) { //���������� �������� �� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	text* var = new(std::nothrow) text;
	if (var == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp->snt = menuForSentence(NULL); //����� ���� �����������
	if (tmp == NULL) {
		if (l != NULL) {
			var->snt = NULL;
			var->prev = l->prev;
			var->next = l;
			l->prev = var;
			l = l->prev;
			if (l->prev != NULL)
				(l->prev)->next = var;
			return l;
		}
		else {
			var->snt = NULL;
			var->prev = NULL;
			var->next = NULL;
			return l = var;
		}
	}
	if (!l->size(l)) {
		tmp->next = NULL;
		tmp->prev = NULL;
		return tmp;
	}
	else {
		tmp->next = l;
		tmp->prev = l->prev;
		l->prev = tmp;
		l = l->prev;
		if (l->prev != NULL) {
			l = l->prev;
			l->next = tmp;
		}
		while (l->prev != NULL)
			l = l->prev;
		return l;
	}
}
void simpleSentenceOutput(sentence* l) { //����� �����������
	while (l != NULL) {
		word* var = new(std::nothrow) word;
		if (var == NULL) {
			std::cout << "Error. Memory cannot be allocated!\n";
			exit(-1);
		}
		var = l->w;
		l->next == NULL ? std::cout << var->s : std::cout << var->s << " ";
		l = l->next;
	}
}
text* text::addElementAfterPtr(text* l, sentence* bufer, text* root) { //���������� �������� �� ������ ����� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	sentence* newSnt = new(std::nothrow) sentence;
	if (newSnt == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	if (l != NULL) {
		if (l->next == NULL) {
			newSnt = bufer;
			tmp->snt = newSnt;
			tmp->next = NULL;
			tmp->prev = l;
			l->next = tmp;
			l = root;
			return l;
		}
		text* var = new(std::nothrow) text;
		if (var == NULL) {
			std::cout << "Error. Memory cannot be allocated\n";
			exit(-1);
		}
		newSnt = bufer;
		var->snt = newSnt;
		tmp = l;
		if (l->next != NULL) {
			l = l->next;
			l->prev = var;
			var->next = l;
			var->prev = tmp;
			l = l->prev; l = l->prev;
			l->next = var;
			l = root;
			return l;
		}
		else {
			tmp = l->next;
			l->next = var;
			var->next = tmp;
			var->prev = l;
			l = root;
			return l;
		}
	}
	else {
		newSnt = bufer;
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->snt = newSnt;
		return tmp;
	}
}
text* text::addElementBeforePtr(text* l, sentence* bufer, text* root, bool& flag) { //���������� �������� �� ������ �� ���������
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	text* var = new(std::nothrow) text;
	if (var == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	sentence* newSnt = new(std::nothrow) sentence;
	if (newSnt == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	newSnt = bufer;
	var->snt = newSnt;
	if (l != NULL) {
		if (l->prev != NULL) {
			tmp = l;
			l = l->prev;
			l->next = var;
			var->prev = l;
			var->next = tmp;
			tmp = l;
			l = l->next; l = l->next;
			l->prev = var;
			while (l->prev != NULL)
				l = l->prev;
			l = root;
			return l;
		}
		else {
			tmp = l->prev;
			l->prev = var;
			var->prev = tmp;
			var->next = l;
			l = l->prev;
			flag = true;
			return l;
		}
	}
	else {
		tmp->snt = newSnt;
		tmp->prev = NULL;
		tmp->next = NULL;
		return tmp;
	}
}
stack* stack::makeTxtNull(stack* l) { //��������� ������
	l->txt = NULL;
	return l;
}
void text::output(text* l, text* root) { //����� ������ (��� ������, ��� � ��������)
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = root;
	int ptrPos = getPointerPos(l, root);
	int count = 0;
	while (tmp != NULL) {
		sentence* snt = new(std::nothrow) sentence;
		snt = tmp->snt;
		if (snt != NULL) {
			if (count == ptrPos) {
				std::cout << "|" << "\033[34m"; simpleSentenceOutput(snt); std::cout << "\033[0m" << "|";
			}
			else { std::cout << "|"; simpleSentenceOutput(snt); std::cout << "|"; }
		}
		else {
			count == ptrPos ? std::cout << "\033[34m| <empty> |\033[0m" : std::cout << "| <empty> |";
		}
		count++;
		tmp = tmp->next;
	}
	std::cout << std::endl << std::endl;
	count = root->size(root);
	tmp = root;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	while (tmp != NULL) {
		sentence* var = new(std::nothrow) sentence;
		var = tmp->snt;
		if (var != NULL) {
			if ((count - 1) == ptrPos) {
				std::cout << "|" << "\033[34m"; simpleSentenceOutput(var); std::cout << "\033[0m" << "|";
			}
			else {
				std::cout << "|"; simpleSentenceOutput(var); std::cout << "|";
			}
		}
		else {
			(count - 1) == ptrPos ? std::cout << "\033[34m| <empty> |\033[0m" : std::cout << "| <empty> |";
		}
		count--;
		tmp = tmp->prev;
	}
	std::cout << std::endl;
}
stack* stack::setText(stack* st, text* txt) {
	stack* tmp = new(std::nothrow) stack;
	if (tmp == NULL) {

	}
	tmp->txt = txt;
	if (!st)
		tmp->next = NULL;
	else
		tmp->next = st;
	//st->txt = txt;
	return tmp;
}
stack* menuForText(text* t) { //���� ������
	system("cls");
	text* l = NULL;
	text* root = NULL;
	sentence* bufer = NULL;
	int task, ptrPos;
	bool isCreated = false; //���� ������ ������ � �������
	stack* top = new(std::nothrow) stack;
	if (top == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	if (!t->isEmpty(t))
		root = l = t;
	while (1) {
		if (bufer) {
			std::cout << "\033[33mbufer >> \033[0m"; simpleSentenceOutput(bufer); std::cout << std::endl; //����� ������, ���� �� �� ����
		}
		if (!l->isEmpty(l)) //�������� �� ������� ������
			l->output(l, root); //����� ������
		else std::cout << "text list is empty\n";
		std::cout << "choose what to do with text (L2)\n\n";
		std::cout << "choose '1' to start working with text list\n";
		std::cout << "choose '2' to make list empty\n";
		std::cout << "choose '3' to check if list is empty\n";
		std::cout << "choose '4' to set pointer to start\n";
		std::cout << "choose '5' to set pointer to the end\n";
		std::cout << "choose '6' to check if pointer is located at start\n";
		std::cout << "choose '7' to check if pointer is located at the end\n";
		std::cout << "choose '8' to move pointer to the next element\n";
		std::cout << "choose '9' to move pointer to the previous element\n";
		std::cout << "choose '10' to show element value after pointer\n";
		std::cout << "choose '11' to show element value before pointer\n";
		std::cout << "choose '12' to delete element after pointer\n";
		std::cout << "choose '13' to delete element before pointer\n";
		std::cout << "choose '14' to take an element after pointer\n";
		std::cout << "choose '15' to take an element before pointer\n";
		std::cout << "choose '16' to change element after pointer\n";
		std::cout << "choose '17' to change element before pointer\n";
		std::cout << "choose '18' to add an element after pointer\n";
		std::cout << "choose '19' to add an element before pointer\n";
		std::cout << "choose '20' to printt text list\n";
		std::cout << "choose '21' stop working with list\n";
		std::cout << ">> ";
		std::cin >> task;
		system("cls");
		switch (task) {
		case 1:
			if (!isCreated) { //�������� �� ������ ������ � �������
				l->start(l);
				isCreated = true;
			}
			else {
				std::cout << "\033[33mYou have already started working with list\033[0m\n";
			}
			break;
		case 2:
			if (isCreated) { //�������� �� ������ ������ � �������
				root = root->makeEmpty(root);
				l = root;
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 3:
			if (isCreated) { //�������� �� ������ ������ � �������
				l->isEmpty(l) == true ? std::cout << "\033[33mtext list is empty\033[0m\n" : std::cout << "\033[33mtext list is not empty\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 4:
			if (isCreated) { //�������� �� ������ ������ � �������
				l = root;
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 5:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l))
					l = l->toEnd(l);
				else std::cout << "\033[33mtext list is empty\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 6:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l))
					l->isStart(l) == 1 ? std::cout << "\033[33mpointer at start\033[0m\n" : std::cout << "\033[33mpointer is not at start\033[0m\n";
				else {
					std::cout << "\033[33mtext list is empty\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 7:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l))
					l->isEnd(l) == 1 ? std::cout << "\033[33mpointer at the end\033[0m\n" : std::cout << "\033[33mpointer is not at the end\033[0m\n";
				else {
					std::cout << "\033[33mtext list is empty\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 8:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l))
					if (!l->isEnd(l))
						l = l->movePtrNext(l);
					else {
						std::cout << "\033[33mpointer is located at the end. Would you like it to point to start? Press y/n\033[0m\n";
						char c;
						std::cin >> c;
						if (c == 'y')
							l = root;
					}
				else {
					std::cout << "\033[33mtext list is empty\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 9:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l))
					if (!l->isStart(l))
						l = l->movePtrPrev(l);
					else {
						std::cout << "\033[33mpointer is located at start. Would you like it to point at end? Press y/n\033[0m\n";
						char cc;
						std::cin >> cc;
						if (cc == 'y')
							l = l->toEnd(l);
					}
				else {
					std::cout << "\033[33mtext list is empty\033[0m\n";
				}

			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 10:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isEnd(l))
					l->showElementValueAfterPtr(l);
				else {
					std::cout << "\033[33mcannot print element after pointer\033[0m\n";
				}
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 11:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isStart(l))
					l->showElementValueBeforePtr(l);
				else {
					std::cout << "\033[33mcannot print element before pointer\033[0m\n";
				}
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 12:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isEnd(l))
					l->deleteAfterPtr(l);
				else std::cout << "\033[33mcannot delete non existing elements\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 13:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isStart(l))
					root = l->deleteBeforePtr(l, root);
				else std::cout << "\033[33mcannot delete non existing elements\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 14:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isEnd(l)) {
					if (l->getSentence(l->movePtrNext(l)) != NULL) {
						bufer = returnNewSentence(l->getSentence(l->movePtrNext(l)));
						l->deleteAfterPtr(l);
						std::cout << "\033[33myou put\033[0m "; simpleSentenceOutput(bufer); std::cout << "\033[33m in bufer\033[0m\n";

					}
					else {
						std::cout << "you can`t take empty element in bufer! Deleting it...\n";
						l->deleteAfterPtr(l);
					}
				}
				else std::cout << "\033[33mcannot take element here\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 15:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isStart(l)) {
					if (l->getSentence(l->movePtrPrev(l)) != NULL) {
						ptrPos = getPointerPos(l, root);
						bufer = returnNewSentence(l->getSentence(l->movePtrPrev(l)));
						root = l->deleteBeforePtr(l, root);
						l = root;
						std::cout << "\033[33myou put \033[0m"; simpleSentenceOutput(bufer); std::cout << "\033[33m in bufer\033[0m\n";
						if (getPointerPos(l, root) < ptrPos && l->size(l) != 1) {
							int pos = getPointerPos(l, root) + 1;
							for (int i = 0; pos < ptrPos; ++i, pos++)
								l = l->movePtrNext(l);
						}
					}
					else {
						std::cout << "\033[33m you can`t take empty element in bufer! Deleting it...\n\033[0m";
						root = root->deleteBeforePtr(l, root);
					}
				}
				else std::cout << "\033[33mcannot take non existing elements in bufer\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 16:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isEnd(l))
					l->changeElementAfterPtr(l);
				else std::cout << "\033[33mcannot change non existing elements\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 17:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (!l->isEmpty(l) && !l->isStart(l)) {
					root = l->changeElementBeforePtr(l);
					l = root;
				}
				else std::cout << "\033[33mcannot change non existing elements\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 18:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (bufer != NULL) {
					std::cout << "\033[33mbufer is not empty. Would you like to add element from bufer? Press y/n: \033[0m\n";
					char s;
					std::cin >> s;
					if (s == 'y') {
						ptrPos = getPointerPos(l, root);
						l == NULL ? root = l->addElementAfterPtr(l, bufer, root), l = root : l = l->addElementAfterPtr(l, bufer, root);
						for (int i = 0; i < ptrPos; ++i) {
							if (l->movePtrNext(l) != NULL) {
								l = l->movePtrNext(l);
							}
						}

					}
					else {
						ptrPos = getPointerPos(l, root);
						root = l->push_back_after_ptr(l, root);
						l = root;
						for (int i = 0; i < ptrPos; ++i) {
							if (l->movePtrNext(l) != NULL) {
								l = l->movePtrNext(l);
							}
						}
					}
				}
				else {
					ptrPos = getPointerPos(l, root);
					root = l->push_back_after_ptr(l, root);
					l = root;
					for (int i = 0; i < ptrPos; ++i) {
						if (l->movePtrNext(l) != NULL) {
							l = l->movePtrNext(l);
						}
					}
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 19:
			if (isCreated) { //�������� �� ������ ������ � �������
				ptrPos = getPointerPos(l, root) + 1;
				if (bufer != NULL) {
					std::cout << "\033[33mbufer is not empty. Would you like to add element from bufer? Press y/n: \033[0m\n";
					char s;
					bool flag = false;
					std::cin >> s;
					if (s == 'y') {
						l == NULL ? root = l->addElementBeforePtr(l, bufer, root, flag), l = root : root->addElementBeforePtr(l, bufer, root, flag);
						if (flag)
							root = l = l->movePtrPrev(l);
						if (getPointerPos(l, root) < ptrPos && l->size(l) != 1) {
							for (int i = 0; getPointerPos(l, root) < ptrPos; ++i)
								l = l->movePtrNext(l);
						}

					}
					else {
						root = l->push_back_before_ptr(l, root);
						l = root;
						if (l->movePtrNext(l) != NULL)
							l = l->movePtrNext(l);
					}
				}
				else {
					root = l->push_back_before_ptr(l, root);
					l = root;
					if (l->movePtrNext(l) != NULL)
						l = l->movePtrNext(l);
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 20:
			if (isCreated) { //�������� �� ������ ������ � �������
				if (bufer) {
					std::cout << "\033[33mbufer >> \033[0m"; simpleSentenceOutput(bufer); std::cout << std::endl;
				}
				if (!l->isEmpty(l))
					l->output(l, root);
				else std::cout << "\033[33mtext list is empty\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 21:
			if (isCreated) { //�������� �� ������ ������ � �������
				l = root;
				if (!l->isEmpty(l)) { //�������� ��������� ������
					top = top->setText(top, l);
					return top;
				}
				return top = top->makeTxtNull(top); //���������� ����� � ���� �����
			}
			else std::cout << "You didn`t start working with text\n";
			break;
		default:
			std::cout << "\033[33mwrong commad\033[0m\n";
			break;
		}
	}
}
void stack::start(stack* st) { //������ ������ �� ������
	std::cout << "\033[33mYou have started to work with stack\033[0m\n\n";
	st = NULL;
}
stack* stack::makeEmpty(stack* st) { //�������� �����
	return st = NULL;
}
bool stack::isEmpty(stack* st) { //�������� �� ������� �����
	return st == NULL;
}
void stack::printHeadValue(stack* st) { //����� ��������� �������� �����
	text* tmp = new(std::nothrow) text;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = st->txt;
	if (tmp == NULL) {
		std::cout << "\033[33mhead value >> \033[0m <empty> \n";

	}
	else
		std::cout << "\033[33mhead value >> \033[0m"; simpleTextOutput(tmp); std::cout << std::endl;
}
stack* stack::deleteHead(stack* st) { //�������� ��������� �������� �����
	st->dicCount();
	if (st->next != NULL) {
		st->next->count = st->count;
		return st = st->next;
	}
	return st = st->next;
}
stack* stack::takeHead(stack* st) {
	return st;
}
text* stack::getText(stack* st) {
	return st->txt;
}
stack* stack::changeHeadValue(stack* st) { //��������� ��������� �������� �����
	int prevCount = st->getCount();
	stack* tmp = new(std::nothrow) stack;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	tmp = st->next;
	st = menuForText(st->txt);
	st->next = tmp;
	st->changeCount(prevCount);
	return st;
}
stack* stack::push_back(stack* st) { //���������� �������� � ����
	if (st == NULL) {
		st = menuForText(NULL); //���� ������
		st->next = NULL;
		st->incCount();
	}
	else if (!st->getCount()) {
		st = menuForText(NULL); ///���� ������
		st->next = NULL;
		st->incCount();
	}
	else {
		stack* tmp = new(std::nothrow) stack;
		if (tmp == NULL) {
			std::cout << "Error. Memory cannot be allocated\n";
			exit(-1);
		}
		int prevCount = st->getCount();
		tmp = st;
		st = menuForText(NULL); ///���� ������
		st->next = tmp;
		st->count = prevCount;
		st->incCount();
	}
	return st;
}
stack* stack::putBufer(stack* st, stack* bufer) { //��������� �������� �� ������
	stack* tmp = new(std::nothrow) stack;
	if (tmp == NULL) {
		std::cout << "Error. Memory cannot be allocated\n";
		exit(-1);
	}
	if (st != NULL) {
		int prevCount = st->count + 1;
		if (st->count == 0) {
			st->txt = bufer->txt;
			st->next = NULL;
			st->count = 1;
			return st;
		}
		tmp->next = st->next;
		tmp->txt = st->txt;
		st->txt = bufer->txt;
		st->next = tmp;
		st->changeCount(prevCount);
		return st;
	}
	else {
		tmp->next = NULL;
		tmp->txt = bufer->txt;
		st = tmp;
		st->changeCount(1);
	}
}
void simpleTextOutput(text* l) { //����� ������
	while (l != NULL) {
		sentence* snt = new(std::nothrow) sentence;
		if (snt == NULL) {
			std::cout << "Error. Memory cannot be allocated!\n";
			exit(-1);
		}
		snt = l->snt;
		if (snt != NULL) {
			std::cout << " ";
			simpleSentenceOutput(snt);
			std::cout << " ";
			l = l->movePtrNext(l);
		}
		else {
			std::cout << " <empty> ";
			l = l->movePtrNext(l);
		}
	}
}
stack* stack::retNextElement(stack* st) { //����������� ���������� �������� �����
	return st = st->next;
}
void stack::output(stack* st) { //����� �����
	while (st != NULL) {
		text* txt = new(std::nothrow) text;
		txt = st->txt;
		std::cout << "|";
		if (st->txt != NULL && txt->getSentence(txt) != NULL) {
			std::cout << ""; simpleTextOutput(txt); std::cout << "";
		}
		else {
			std::cout << " <empty> ";
			if (txt != NULL)
				txt = txt->movePtrNext(txt);
			if (txt != NULL)
				std::cout << ""; simpleTextOutput(txt); std::cout << "";
		}
		std::cout << "|";
		st = st->next;
	}
	std::cout << std::endl;
}
int main() {
	stack* st = new(std::nothrow) stack(); //�������� ������� ������ stack � ����� ������������ �� ���������
	if (st == NULL) { //�������� �� ��, ���������� �� ������
		std::cout << "Error. Memory cant be allocated\n";
	}
	stack* bufer = NULL;
	int task, prevCount = 0;
	bool isCreated = false; //����, ������� ����������� ������ �� ������ �� ������
	while (1) {
		if (!st->isEmpty(st) && st->getCount() > 0) //�������� �� ��, ������ �� ����� � ��������� �� ��
			st->output(st); //����� ������
		else std::cout << "\033[33mstack is empty\033[0m\n";
		std::cout << "choose what to do with stack:\n\n";
		std::cout << "choose '1' to start working with stack\n";
		std::cout << "choose '2' to empty stack\n";
		std::cout << "choose '3' to check if stack is empty\n";
		std::cout << "choose '4' to show head element\n";
		std::cout << "choose '5' to delete head element\n";
		std::cout << "choose '6' to take head element\n";
		std::cout << "choose '7' to change value of the head element\n";
		std::cout << "choose '8' to add an element\n";
		std::cout << "choose '9' to print stack\n";
		std::cout << "choose '10' to finish work with stack\n";
		std::cout << "choose '11' to exit from program\n";
		std::cout << ">> ";
		std::cin >> task;
		system("cls");
		switch (task) {
		case 1:
			if (!isCreated) { //�������� �� ���� �� ������ ������ �� ������
				st->start(st); //������ ������ �� ������
				isCreated = true; //������ ����
			}
			else {
				std::cout << "\033[33mYou have already started working with stack!\033[0m\n\n";
			}
			break;
		case 2:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (!st->isEmpty(st)) {
					st = st->makeEmpty(st);
				}
				else {
					std::cout << "\033[33mstack is already empty\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 3:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (st != NULL)
					st->getCount() == 0 ? std::cout << "\033[33mstack is empty\033[0m\n" : std::cout << "\033[33mstack is not empty\033[0m\n";
				else std::cout << "\033[33mstack is empty\033[0m\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 4:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (st != NULL && st->getCount() != 0) {
					st->printHeadValue(st);
				}
				else {
					std::cout << "\033[33mcan`t show non existing elements\033[0m\n";
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 5:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (!st->isEmpty(st))
					st = st->deleteHead(st);
				else std::cout << "\033[33myou cannot delete in empty stack\033[0m!\n";
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 6:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (!st->isEmpty(st)) {
					if (bufer->getText(st) && bufer->getText(st)->getSentence(bufer->getText(st))) {
						bufer = st->takeHead(st); //�������� �������� ������� ����� � �����
						prevCount = st->getCount(); //��������� ������� ���������� ��������� �����
						if (st->retNextElement(st) != NULL)
							st = st->deleteHead(st); //������� �������� ������� �����
						else {
							st = st->deleteHead(st); //������� �������� ������� �����
							stack* temp = new stack();
							st = temp;
						}
						st->changeCount(prevCount - 1); //������ ���������� ��������� � �����
						std::cout << "\033[33myou put in bufer \033[0m"; st->printHeadValue(bufer); //����� ��������, ������� ������������ �������� � �����
					}
					else {
						std::cout << "\033[33mYou cant put empty elements in bufer! Deleting it...\033[0m\n";
						st = st->deleteHead(st);
					}
				}
				else std::cout << "\033[33mcannot take elements in empty stack\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 7:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (!st->isEmpty(st))
					st = st->changeHeadValue(st); //������ �������� ��������� �������� �����
				else std::cout << "\033[33mcannot change values in empty stack!\033[0m\n";
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 8:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (st != NULL) { //�������� �� ��������� �������� ������� ������ stack
					if (st->getCount() != MAX_ELEMENTS) { //��������� ���������� ��� ������������ ���������
						if (bufer != NULL) {
							std::cout << "\033[33mbufer is not empty. Would you like to add an element from bufer. Press y/n: \033[0m\n";
							char c;
							std::cin >> c;
							if (c == 'y') {
								st = st->putBufer(st, bufer); //���������� 
							}
							else st = st->push_back(st); //���������� �������� � ����
						}
						else st = st->push_back(st); //���������� �������� � ����
					}
					else std::cout << "\033[33mYou cant add more that 5 elements in stack\033[0m!\n";
				}
				else {
					if (bufer != NULL) { //�������� ������ �� �������
						std::cout << "\033[33mbufer is not empty. Would you like to add an element from bufer. Press y/n: \033[0m\n";
						char c;
						std::cin >> c;
						if (c == 'y') {
							st = st->putBufer(st, bufer); //���������� �������� �� ������, ���� �������� �������� ������������
						}
						else st = st->push_back(st); //���������� �������� � ����
					}
					else st = st->push_back(st); //���������� �������� � ����
				}
			}
			else {
				std::cout << "\033[33mwork has not started\033[0m\n";
			}
			break;
		case 9:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				if (st != NULL && st->getCount() != 0) {
					if (bufer != NULL) {
						std::cout << "bufer >> "; st->printHeadValue(bufer);
					}
					if (!st->isEmpty(st))
						st->output(st);
					else std::cout << "\033[33mCant print in empty stack!\033[0m\n";
				}
			}
			else std::cout << "\033[33mwork has not started\033[0m\n";
			break;
		case 10:
			if (isCreated) { //�������� ���� �� ������ ������ �� ������
				std::cout << "\033[33mYou ended working with stack!\033[0m\n";
				st = st->makeEmpty(st); //�������� ��������� �����
				isCreated = false; //������ ����
			}
			else std::cout << "\033[33mYou didnt start working with stack\033[0m\n";
			break;
		case 11:
			if (!isCreated) { //�������� ���� �� ������ ������ �� ������
				std::cout << "\033[33m You choosed to exit from program\033[0m\n";
				exit(3); //����� �� ���������
			}
			else std::cout << "\033[33mYou didn`t finish work with stack\033[0m\n";
			break;

		default:
			std::cout << "\033[33mwrong command\033[0m\n";
			break;
		}
	}
}