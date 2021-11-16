#pragma once
// ------------------Отделение обьявления от реализации------------------

// Когда в классе количество методов достигает больших размеров, проще 
// обьявить функции в классе и реализовать за классом

// -----------------------Пример кода-----------------------------
//  class Date
//  {
//  private:
//      int m_day;
//      int m_month;
//      int m_year;
//
//  public:
//      Date(int day, int month, int year);
//
//      void SetDate(int day, int month, int year);
//
//      int getDay() { return m_day; }
//      int getMonth() { return m_month; }
//      int getYear() { return m_year; }
//  };
//
//  // Конструктор класса Date 
//  Date::Date(int day, int month, int year)
//  {
//     SetDate(day, month, year);
//  }
//
//  // Метод класса Date 
//  void Date::SetDate(int day, int month, int year)
//  {
//      m_day = day;
//      m_month = month;
//      m_year = year;
//  }


// --------Пример кода со списком инициализации-----------------



//  class Mathem
//  {
//  private:
//      int m_value = 0;
//
//  public:
//      Mathem(int value = 0);
//
//      Mathem& add(int value);
//      Mathem& sub(int value);
//      Mathem& divide(int value);
//
//      int getValue() { return m_value; }
//  };
//
//  Mathem::Mathem(int value) : m_value(value)
//  {
//  }
//
//  Mathem& Mathem::add(int value)
//  {
//      m_value += value;
//      return *this;
//  }
//
//  Mathem& Mathem::sub(int value)
//  {
//      m_value -= value;
//      return *this;
//  }
//
//  Mathem& Mathem::divide(int value)
//  {
//      m_value /= value;
//      return *this;
//  }


// !!!!!Реализацию функций можно совершать в разных заголовочных файлах, 
// тоесть обьявить в файле с классом, а реализовать в другом файле без ошибок

// -------------  Const в классах--------------------------------------------

// const int value1 = 6; // копирующая инициализация
// const int value2(8); // прямая инициализация
// const int value3{ 11 }; // uniform-инициализация (C++11)

// Любой тип данных, или обьект в классе можно сделать константным,
// в последующих действиях нельзя будет изменять эти параметры, при попытке изменения значеня, будет ошибка


//  -------Пример ошибки при изменении константы-----------------------------
// class Anything
// {
// public:
//     int m_value;
//
//     Anything() : m_value(0) { }
//
//     void setValue(int value) { m_value = value; }
//     int getValue() { return m_value; }
// };
//
// int main()
// {
//     const Anything anything; // вызываем конструктор по умолчанию
//
//     anything.m_value = 7; // ошибка компиляции: нарушение const
//     anything.setValue(7); // ошибка компиляции: нарушение const
//
//     return 0;
// }


// ------------Константные методы классов-----------------------------


// Рассмотрим строку в мейне для предыдущего кода:
//     std::cout << anything.getValue();


// Вызов не будет работать, даже без попыток изменения данны, чтобы решить эту проблемму, 
// нужно доказать что метод константный, тоесть в прототипе функции прямо указать константу


//  -------------------Пример------------------------------------------


// class Anything
// {
// public:
//     int m_value;
//
//     Anything() { m_value = 0; }
//
//     void resetValue() { m_value = 0; }
//     void setValue(int value) { m_value = value; }
//
//     int getValue() const { return m_value; } // ключевое слово const находится после списка параметров, но перед телом функции
// };


// При прототипе функции так же нужно указыватьна константу, например:


// class Anything
// {
// public:
//     int m_value;
//
//     Anything() { m_value = 0; }
//
//     void resetValue() { m_value = 0; }
//     void setValue(int value) { m_value = value; }
//
//     int getValue() const;                 - обратите внимание на ключевое слово const здесь
// };
//
// int Anything::getValue() const            - и здесь
// {
//     return m_value;
// }


// !!!!!!!Конструкторы не могут быть константными!!!!!!!!!!!
// Рекомендуется делать все методы, которые не изменяют данные константными


//  Поскольку мы не можем вызывать неконстантные методы через константные объекты,
//  нужно методы обьявить константными


// ------------------------------Заключение-------------------------------------------
//  Любой метод, который не изменяет данные объекта класса, должен быть const!


// ------------------Статические переменные-члены класса-----------------------------

// Статические переменные это переменная которая после выхода из блока, в котором они обьявлены,
// сохраняют свое значение, например:

//
// int generateID()
// {
//     static int s_id = 0;
//     return ++s_id;
// }
//
// int main()
// {
//     std::cout << generateID() << '\n';
//     std::cout << generateID() << '\n';
//     std::cout << generateID() << '\n';
// 
//     return 0;
// }


// Результат:   1   2   3 


// Так как использование глобальных переменных - это зло, нужно ограничивать область видимости 
// статических переменных, в этом поможет ключевое слово --static--


//  Рассмотрим код:


// class Anything
// {
// public:
//     int m_value = 3;
// };
//
// int main()
// {
//     Anything first;
//     Anything second;
//
//     first.m_value = 4;
//
//     std::cout << first.m_value << '\n';
//     std::cout << second.m_value << '\n';
//
//     return 0;
// }


// Результат: 4
//            3


// !!! Так как при создании обьекта класса, создается его собственная копия всех переменных класса, 
// в этом случает мы обьявили два обьекта класса Anything, у нас будет две копии m_value: first.m_value и second.m_value
// Так как это разные значения, результат 4 и 3


// Рассмотрим другой код:


// class Anything
// {
// public:
//     static int s_value;
// };
//
// int Anything::s_value = 3;
//
// int main()
// {
//     Anything first;
//     Anything second;
//
//     first.s_value = 4;
//
//     std::cout << first.s_value << '\n';
//     std::cout << second.s_value << '\n';
//     return 0;
// }

// Результат: 4
//            4 

// Так как мы обьявили переменную --s_value-- статической, она является общей для всех обьектов, 
// следовательно first.m_value и second.m_value, это одна и та же переменная, поэтому через первый обьект,
// мы можем получить второй обьект


// Статические члены не связаны с объектами класса, тоесть статическая переменная создается в начале работы
// программы, и удаляется в конце работы программы, тоесть принадлежат классу, а не обьектам класса, 
// и поэтому мы может вызвать эту переменную через имя класса, и оператор разрешения области видимости(::)

// Пример:     Anything::s_value;

// Определение и инициализация статических переменных-членов класса


// При обьявлении статической переменной внутри класса, мы сообщаем компилятору о существовании
// статической переменной, но не о её определении. Поскольку статические переменные не являются 
// частью отдельного обьекта класса, мы должны явно определить статический член вне класса, в коде выше 
// это строка:		int Anything::s_value = 3; // определяем статическую переменную-член
// Тоесть мы определили статическую переменную, и дали ей значение 3, если бы мы этого не сделали, то 
// компилятор посчитал бы переменную s_value значению 0

// Статическая переменная не попадает под public, private, protected

//  Инициализация статических переменных - членов внутри тела класса

// Если статическая переменная-член является константной, её можно инициализировать в теле класса, например:

// class Anything
// {
// public:
//     static const int s_value = 5; // статическую константную переменную типа int можно объявить и инициализировать напрямую
// };

// Использование этих методов:



// class Anything
// {
// private:
//     static int s_idGenerator;
//     int m_id;
//
// public:
//     Anything() { m_id = s_idGenerator++; } --- увеличиваем значение идентификатора для следующего объекта
//
//     int getID() const { return m_id; }
// };
//
//   ----Мы определяем и инициализируем s_idGenerator несмотря на то, что он объявлен как private.
//   ----Это нормально, поскольку определение не подпадает под действия спецификаторов доступа
// int Anything::s_idGenerator = 1; ---- начинаем наш ID-генератор со значения 1
//
// int main()
// {
//     Anything first;
//     Anything second;
//     Anything third;
//
//     std::cout << first.getID() << '\n';    Результат: 1
//     std::cout << second.getID() << '\n';   Результат: 2
//     std::cout << third.getID() << '\n';    Результат: 3
//     return 0;
// }



//  -----------Статические методы класса--------------------------------

// Статические переменные это члены которые принадлежат классу, а не его обьектам


// Статические переменные, являются открытыми, но что если они будут закрытыми, например:

// class Anything
// {
// private:
//     static int s_value;
//
// };
//
// int Anything::s_value = 3; // определение статического члена, несмотря на то, что он является private
//
// int main()
// {
//     // Как получить доступ к Anything::s_value здесь, если s_value является private?
// }


// Для решения этой проблеммы можно создать статический метод, тоесть:


// class Anything
// {
// private:
//     static int s_value;
// public:
//     static int getValue() { return s_value; } // статический метод
// };
//
// int Anything::s_value = 3; // определение статической переменной-члена класса
//
// int main()
// {
//     std::cout << Anything::getValue() << '\n';
// }


// У статических методов есть особенности:


// 1.Так как статические методы не привязаны к обьекту, у них нет указателя (*this)
// 2. Статическе методы могут напрямую общаться со статическими переменными,
// но не могут общаться с нестатическими переменными, изза того, что нестатические переменные 
// принадлежат обьекту класса, а статические методы - нет!!

//Статические методы можно определять вне класса, например:


//  class IDGenerator
//  {
//  private:
//      static int s_nextID; ----объявление статической переменной-члена
//
//  public:
//      static int getNextID();  ----объявление статического метода
//  };
//
//  ----Определение статической переменной-члена находится вне тела класса. Обратите внимание, мы не используем здесь ключевое слово static.
//  ----Начинаем генерировать ID с 1
//  int IDGenerator::s_nextID = 1;
//
//  -----Определение статического метода находится вне тела класса. Обратите внимание, мы не используем здесь ключевое слово static
//  int IDGenerator::getNextID() { return s_nextID++; }
//
//  int main()
//  {
//      for (int count = 0; count < 4; ++count)
//          std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';
//
//      return 0;
//  }


//  Результат:

// The next ID is : 1
// The next ID is : 2
// The next ID is : 3
// The next ID is : 4

// Так как все переменные и функции этого класса являются статическими, нам не нужно создавать обьект 
// этого класса для работы с ним!!!


// !!!!Предупреждение о классах со всеми статическими членами!!!!!!!!!!

// 1. Так как все статические члены создаются только 1 раз, то несколько копий этого класса быть не может,
// например: если нам нужны 2 независимых обьекта класса Class, то это будет невозможным 
// 2. Статические классы являются глобальными, что передается со всеми минусами глобальных переменных, 
// по типу изменения одного члена, который может изменить весь код	



//  Код инициализации статической переменной-члена(цикл) пример:


//  class Something
//  {
//  private:
//	static std::vector<char> s_mychars;
//
//  public:
//  	class _nested ----- определяем вложенный класс с именем _nested
//	  {
//	  public:
//		  _nested() ----- конструктор _nested() инициализирует нашу статическую переменную-член
//		  {
//			  s_mychars.push_back('o');
//			  s_mychars.push_back('a');
//	       	  s_mychars.push_back('u');
//	  	  	  s_mychars.push_back('i');
//			  s_mychars.push_back('e');
//		  }
//	  };
//
//	  // Статический метод для вывода s_mychars
//	  static void getSomething() {
//		  for (auto const& element : s_mychars)
//			  std::cout << element << ' ';
//	  }
//  private:
//	  static _nested s_initializer; ----используем статический объект класса _nested для гарантии того, что конструктор _nested() выполнится
//  };
//
//  std::vector<char> Something::s_mychars; ---- определяем нашу статическую переменную-член
//  Something::_nested Something::s_initializer; ----- определяем наш статический s_initializer, который вызовет конструктор _nested() для инициализации s_mychars
//
//  int main() {
//  	Something::getSomething();
//  	return 0;
//  }


//  Результат: o a u i e


// Заключение:
// Статические методы могут использоваться для работы со статическими переменными-членами класса.
// Для работы с ними не требуется создавать объекты класса.




// ---------------Дружественные функции и классы----------------------------------

// Дружественная функция нужна для доступа к закрытым членам класса, то же самое что если бы она сама 
// была членом этого класса. По сути это обычная функция

//  Для объявления дружественной функции используется ключевое слово ---friend---- перед прототипом функции, 
//  которую вы хотите сделать дружественной классу. 


//  class Anything
//  {
//  private:
//      int m_value;
//  public:
//      Anything() { m_value = 0; }
//      void add(int value) { m_value += value; }
//
//      ---- Делаем функцию reset() дружественной классу Anything
//      friend void reset(Anything& anything);
//  };
//
//  ------ Функция reset() теперь является другом класса Anything
//  void reset(Anything& anything)
//  {
//      ------ И мы имеем доступ к закрытым членам объектов класса Anything
//      anything.m_value = 0;
//  }
//
//  int main()
//  {
//      Anything one;
//      one.add(4); ------ добавляем 4 к m_value
//      reset(one); ------ сбрасываем m_value в 0
//
//      return 0;
//  }


//  ----Функция может быть дружественной сразу для нескольких классов, например:


//  class Humidity;  ----Прототип класса
//
//  class Temperature
//  {
//  private:
//      int m_temp;
//  public:
//      Temperature(int temp = 0) { m_temp = temp; }
//  
//      friend void outWeather(const Temperature& temperature, const Humidity& humidity);
//  };
//
//  class Humidity
//  {
//  private:
//      int m_humidity;
//  public:
//      Humidity(int humidity = 0) { m_humidity = humidity; }
//
//      friend void outWeather(const Temperature& temperature, const Humidity& humidity);
//  };
//
//  void outWeather(const Temperature& temperature, const Humidity& humidity)
//  {
//      std::cout << "The temperature is " << temperature.m_temp <<
//          " and the humidity is " << humidity.m_humidity << '\n';
//  }
//
//  int main()
//  {
//      Temperature temp(15);
//      Humidity hum(11);
//
//      outWeather(temp, hum);
//
//      return 0;
//  }


// ---------Один класс может быть дружественным другому классу--------------

//  class Values
//  {
//  private:
//      int m_intValue;
//      double m_dValue;
//  public:
//      Values(int intValue, double dValue)
//      {
//          m_intValue = intValue;
//          m_dValue = dValue;
//      }
//
//      -------- Делаем класс Display другом класса Values
//      friend class Display;
//  };
//
//  class Display
//  {
//  private:
//      bool m_displayIntFirst;
//
//  public:
//      Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//      void displayItem(Values& value)
//      {
//          if (m_displayIntFirst)
//              std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//          else ------ или сначала выводим double
//              std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//      }
//  };
//
//  int main()
//  {
//      Values value(7, 8.4);
//      Display display(false);
//
//      display.displayItem(value);
//
//      return 0;
//  }

// Результат: 8.4  7


// !!!!!  Примечания  !!!!!

// 1. Дружественные классы не имеют прямой указатель *this  друг друга
// 2. Если класс 1 является другом классу 2, то это не значит что класс 2 является другом классу 1
// Тоесть нужно указать в обоих классах дружественность



// ------------Дружественные методы---------------



//class Display; // предварительное объявление класса Display
//
//class Values
//{
//private:
//	int m_intValue;
//	double m_dValue;
//public:
//	Values(int intValue, double dValue)
//	{
//		m_intValue = intValue;
//		m_dValue = dValue;
//	}
//
//	// Делаем метод Display::displayItem() другом класса Values
//	friend void Display::displayItem(Values& value); // ошибка: Values не видит полного определения класса Display
//};
//
//class Display
//{
//private:
//	bool m_displayIntFirst;
//
//public:
//	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//	void displayItem(Values& value)
//	{
//		if (m_displayIntFirst)
//			std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//		else // или выводим сначала double
//			std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//	}
//};


// Но это не работающий метод, так как компилятор должен увидеть полное определение класса, 
// в котором дружественный метод определяется (а не только лишь его прототип).
// Поскольку компилятор, прочёсывая последовательно строчки кода не увидел полного определения класса Display,
// но успел увидеть прототип его метода, то он выдаст ошибку в строке определения этого метода дружественным классу Values (строка №16).



// Можно попытаться переместить определение класса  Display выше определения второго класса



//class Display
//{
//private:
//	bool m_displayIntFirst;
//
//public:
//	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//	void displayItem(Values& value) // ошибка: Компилятор не знает, что такое Values
//	{
//		if (m_displayIntFirst)
//			std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//		else // или выводим сначала double
//			std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//	}
//};
//
//class Values
//{
//private:
//	int m_intValue;
//	double m_dValue;
//public:
//	Values(int intValue, double dValue)
//	{
//		m_intValue = intValue;
//		m_dValue = dValue;
//	}
//
//	// Делаем метод Display::displayItem() другом класса Values
//	friend void Display::displayItem(Values& value);
//};



// Поскольку метод Display::displayItem() использует ссылку на объект класса Values в качестве параметра,
// а мы только что перенесли определение Display выше определения Values, то компилятор будет жаловаться,
// что он не знает, что такое Values. Получается замкнутый круг.

// Способы решения:

// 1.Для класса Values используем предварительное объявление.
// 2.Переносим определение метода Display::displayItem() за пределы класса Display,
// и размещаем его после полного определения класса Values.



//class Values; // предварительное объявление класса Values
//
//class Display
//{
//private:
//	bool m_displayIntFirst;
//
//public:
//	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//	void displayItem(Values& value); // предварительное объявление, приведенное выше, требуется для этой строки
//};
//
//class Values // полное определение класса Values
//{
//private:
//	int m_intValue;
//	double m_dValue;
//public:
//	Values(int intValue, double dValue)
//	{
//		m_intValue = intValue;
//		m_dValue = dValue;
//	}
//
//	// Делаем метод Display::displayItem() другом класса Values
//	friend void Display::displayItem(Values& value);
//};
//
//// Теперь мы можем определить метод Display::displayItem(), которому требуется увидеть полное определение класса Values
//void Display::displayItem(Values& value)
//{
//	if (m_displayIntFirst)
//		std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//	else // или выводим сначала double
//		std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//}
//
//int main()
//{
//	Values value(7, 8.4);
//	Display display(false);
//
//	display.displayItem(value);
//
//	return 0;
//}


// Теперь всё работает правильно, но ещё более лучшим решением 
//  было поместить оба класса в разные заголовочные файлы с определенями методов


//----------Задание на проверку----------------------------



//class Vector3D; // сначала говорим компилятору, что класс с именем Vector3D существует
//
//class Point3D
//{
//private:
//	double m_x, m_y, m_z;
//
//public:
//	Point3D(double x = 0.0, double y = 0.0, double z = 0.0)
//		: m_x(x), m_y(y), m_z(z)
//	{
//
//	}
//
//	void print()
//	{
//		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
//	}
//
//	void moveByVector(const Vector3D& v); // чтобы мы могли использовать Vector3D здесь
//	   // Примечание: Мы не можем определить эту функцию здесь, так как Vector3D еще не был определен (компилятор увидит только его предварительное объявление)
//};
//
//class Vector3D
//{
//private:
//	double m_x, m_y, m_z;
//
//public:
//	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
//		: m_x(x), m_y(y), m_z(z)
//	{
//
//	}
//
//	void print()
//	{
//		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
//	}
//
//	friend void Point3D::moveByVector(const Vector3D& v); // Point3D::moveByVector() теперь является другом класса Vector3D
//};
//
//// Теперь, когда Vector3D был определен, мы можем определить функцию Point3D::moveByVector()
//void Point3D::moveByVector(const Vector3D& v)
//{
//	m_x += v.m_x;
//	m_y += v.m_y;
//	m_z += v.m_z;
//}
//
//int main()
//{
//	Point3D p(3.0, 4.0, 5.0);
//	Vector3D v(3.0, 3.0, -2.0);
//
//	p.print();
//	p.moveByVector(v);
//	p.print();
//
//	return 0;
//}

