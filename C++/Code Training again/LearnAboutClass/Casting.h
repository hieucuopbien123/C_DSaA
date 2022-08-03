#pragma once
#ifndef CLASS_H8
#define CLASS_H8

class Cha2 {
public:
	int intCha;
	Cha2() : intCha(1) {};
};
class Con2 : public Cha2 {
public:
	int intCon;
	Con2() : intCon(2) {};
};

#endif // !CLASS_H8