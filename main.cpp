#include <stdio.h>

/// <summary>
/// 楽器
/// </summary>
class MusicalInstrument {
public:
	MusicalInstrument() {};
	virtual ~MusicalInstrument() {};

	// 音だし
	virtual void MakeSound() {};

private:
};

// トランペット
class Trumpet : public MusicalInstrument {
public:
	Trumpet() {};
	~Trumpet() override { printf_s("トランペットを片付けた\n"); };

	// 音だし
	void MakeSound() override { printf_s("華やかなトランペットの音色\n"); };

private:
};

// トロンボーン
class Trombone : public MusicalInstrument {
public:
	Trombone() {};
	~Trombone() override { printf_s("トロンボーンを片付けた\n"); };

	// 音だし
	void MakeSound() override { printf_s("厳かなトロンボーンの音色\n"); };

private:
};

int main() {
	// 楽器の数
	const int musicalInstrumentMax = 3;
	MusicalInstrument* musicalInstruments[musicalInstrumentMax];

	for (int i = 0; i < musicalInstrumentMax; i++) {
		if (i < 1) {
			musicalInstruments[i] = new Trumpet;
		}
		else {
			musicalInstruments[i] = new Trombone;
		}
	}

	for (int i = 0; i < musicalInstrumentMax; i++) {
		printf_s("%d人目の人の音だし\n", i + 1);
		musicalInstruments[i]->MakeSound();
		printf_s("\n");

	}

	for (int i = 0; i < musicalInstrumentMax; i++) {
		delete musicalInstruments[i];
	}

	return 0;
}