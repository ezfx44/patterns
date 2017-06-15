/* Без применения шаблона проектирования Proxy
class Image
{
	int m_id;
	static int s_next;
public:
	Image()
	{
		m_id = s_next++;
		cout << "   $$ ctor: " << m_id << '\n';
	}
	~Image()
	{
		cout << "   dtor: " << m_id << '\n';
	}
	void draw()
	{
		cout << "   drawing image " << m_id << '\n';
	}
};
int Image::s_next = 1;

int main()
{
	Image images[5];

	for (int i; true;)
	{
		cout << "Exit[0], Image[1-5]: ";
		cin >> i;
		if (i == 0)
			break;
		images[i - 1].draw();
	}
}
*/

// С применением шаблона
class RealImage
{
	int m_id;
public:
	RealImage(int i)
	{
		m_id = i;
		cout << "   $$ ctor: " << m_id << '\n';
	}
	~RealImage()
	{
		cout << "   dtor: " << m_id << '\n';
	}
	void draw()
	{
		cout << "   drawing image " << m_id << '\n';
	}
};

//Класс-обертка с "дополнительным уровнем косвенности"
class Image
{
//Класс-обертка содержит указатель на реальный класс
	RealImage *m_the_real_thing;
	int m_id;
	static int s_next;
public:
	Image()
	{
		m_id = s_next++;
//Инициализируется нулевым значением
		m_the_real_thing = 0;
	}
	~Image()
	{
		delete m_the_real_thing;
	}
	void draw()
	{
//Реальный объект создается при поступлении запроса "на первом использовании"
		if (!m_the_real_thing)
			m_the_real_thing = new RealImage(m_id);
//Запрос всегда делегируется реальному объекту
		m_the_real_thing->draw();
	}
};
int Image::s_next = 1;

int main()
{
	Image images[5];

	for (int i; true;)
	{
		cout << "Exit[0], Image[1-5]: ";
		cin >> i;
		if (i == 0)
			break;
		images[i - 1].draw();
	}
}