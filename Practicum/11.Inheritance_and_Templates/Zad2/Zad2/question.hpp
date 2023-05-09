#ifndef QUESTION_H
#define QUESTION_H

class Question {
private:
	char* q;
	char* a;

	void setQ(const char* q);
	void setA(const char* a);

	void free();
	void copy(const Question& other);
	void move(Question&& other);

public:
	Question();
	Question(const char* q, const char* a);

	Question(const Question& other);
	Question(Question&& other);

	Question& operator=(const Question& other);
	Question& operator=(Question&& other);

	~Question();
};
#endif // !QUESTION_H
