// Singleton.h
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&);
	Singleton& operator=(Singleton&);
public:
	static Singleton& getInstance() {
		static Singleton  instance;
		return instance;
	}
};