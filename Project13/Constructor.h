#pragma once
//  ............................Конструкторы...................................................

//  Позволяет инициализировать переменные значениями по умолчанию, либо пользователем, 
//  так же позволяет открывать файл или базу данных
//  1.Название конструктора должно быть как у названия класса
//  2.Конструкторы записываются без типа данных, тоесть не имеют их
//  Используется !!ТОЛЬКО ДЛЯ ИНИЦИАЛИЗАЦИИ!!
//



//  сlass Fraction
//  {
//  private:
//    int m_numerator;
//    int m_denominator;
//
//  public:
//    Fraction() // конструктор по умолчанию 
//    {
//         m_numerator = 0;
//         m_denominator = 1;
//    }
//
//    int getNumerator() { return m_numerator; }
//    int getDenominator() { return m_denominator; }

//    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
//  };

//  int main()
//  {
//    Fraction drob; // так как нет никаких аргументов, то вызывается конструктор по умолчанию Fraction()

//    std::cout << drob.getNumerator() << "/" << drob.getDenominator() << '\n';
//  ---------------------Результат будет 0/1, тоесть значения по умолчанию------------------
//    return 0;
//  }



//  Fraction drob(4, 5); // инициализируем напрямую, вызывается конструктор Fraction(int, int)
//  Результат 4/5

//  Fraction seven(7); // вызывается конструктор Fraction(int, int), второй параметр использует значение по умолчанию
//  Тоесть то же самое что Fraction drob(7, 1)
//  Результат 7/1


//  ................... Список инициализации членов класса.............................................
//  По сути то же самое что и присваивание значений переменным, но инициализация считается более эфективной
//  и лучше использовать её, с помощью списка инициализации, это можно сделать более удобно
//  ............................................................................................
//  RGBA(int red=0, int=0,int=0, int=255) - присвоение по умолчанию в конструкторе
//    : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha} - инициализация напрямую членов класса
//  ............................................................................................


//  ---------------------КОД С ПРИСВАИВАНИЕМ, НЕ ИНИЦИАЛИЗАЦИЕЙ-----------------------------------


//  class Values
//  {
//  private:
//    int m_value1;
//    double m_value2;
//    char m_value3;
//
//  public:
//    Values()
//    {
//        // Это всё операции присваивания, а не инициализация
//        m_value1 = 3;
//        m_value2 = 4.5;
//        m_value3 = 'd';
//    }
//  };


//  ---------------КОД С ИНИЦИАЛИЗАЦИЕЙ, ПРИ ПОМОЩИ СПИСКА ИНИЦИАЛИЗАЦИИ-------------------------	



//  class Values
//  {
//  private:
//    int m_value1;
//    double m_value2;
//    char m_value3;
//
//  public:
//    Values() : m_value1(3), m_value2(4.5), m_value3('d') // напрямую инициализируем переменные-члены класса
//    {
//        // Нет необходимости использовать присваивание
//    }
//
//    void print()
//    {
//        std::cout << "Values(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
//    }
//  };


//  -------------------------------Тестируемое задание на инициализацию-----------------------------

//  //class RGBA
//  {
//
//	std::uint8_t m_red;
//	std::uint8_t m_green ;
//	std::uint8_t m_blue;
//	std::uint8_t m_alpha ;
//
//  public:
//	RGBA(std::uint8_t red=0, std::uint8_t green=0, std::uint8_t blue=0, std::uint8_t alpha=255)
//		: m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
//	{
//
//	}
//	void print()
//	{
//		std::cout << "r=" << static_cast<int>(m_red) <<
//			" g=" << static_cast<int>(m_green) <<
//			" b=" << static_cast<int>(m_blue) <<
//			" a=" << static_cast<int>(m_alpha) << '\n';
//
//	}
//  };
//  main

//  RGBA color(0, 135, 135);
//  color.print();



//  ........................................................................................
//  ...................Инициализация нестатических обьектов класса..........................
//  Задают значение по умолчанию, которое может использоваться любыми другими конструкторами,
//  при этом конструкторы могут задавать свои параметры
//  ........................................................................................
//  class Thing
//  {
//  private:
//	  std::string m_color = { "blue" };
//   	double m_radius=20;
//
//  public:
//	
//	Thing()
//	{	
//  Выводит обычные параметры по умолчанию заданны изначально
//	}
//
//	
//	Thing(const std::string& color):m_color(color)
//	{	
//  Выводит заданный параметр color пользователем и параметр по умолчанию radius
//	}
//
//	
//	Thing(double radius):m_radius(radius)
//	{	
//  Выводит заданный параметр radius пользователем и параметр по умолчанию color
//	}
//
//	
//	Thing(const std::string& color, double radius) :m_color(color),m_radius(radius)
//	{
//  Выводит параметры заданные пользователем
//	}
//
//	void print()
//	{
//		std::cout << "color: " << m_color << " and radius: " << m_radius << '\n';
//	}
//  };


//  main

//  Thing defl;
//  defl.print();

//  Thing red("red");
//  red.print();

//  Thing thirty(30.0);
//  thirty.print();

//  Thing redThirty("red", 30.0);
//  redThirty.print();

//  Результат:
//  color: blue and radius : 20
//  color : red and radius : 20
//  color : blue and radius : 30
//  color : red and radius : 30



//  ........................................................................................
//  ...........................Делегирующие конструкторы....................................
//  Делегирующий консруктор-конструктор который может вызывать другой конструктор, чтобы сократить код
//  ---Один делегирующий конструктор может вызвать только один другой конструктор
//  ........................................................................................




//  class Employee
//  {
//  private:
//    int m_id;
//    std::string m_name;
//
//  public:
//    Employee(int id = 0, const std::string& name = "") :
//        m_id(id), m_name(name)
//    {
//        std::cout << "Employee " << m_name << " created.\n";
//    }
//
//    // Используем делегирующие конструкторы для сокращения дублированного кода
//    Employee(const std::string& name) : Employee(0, name) { }
//  };

//  main

//  Employee a;
//  Employee b("Ivan");

//  Результат:

//  Employee a;
//   Employee  created.

//  Employee b("Ivan");
//  Employee Ivan created.



//  ....................................................................................
//  -----------------------------------Деструкторы--------------------------------------

//  Конструкторы призначены для инициализации обьекта класса, деструкторы работают наоборот,
//  тоесть очищает память, после удаления обьекта класса (Работает с динамической памятью)
//  !!!!!!!!!!!!!ОБЯЗАТЕЛЬНО ИСПОЛЬЗОВАТЬ ПРИ ДИНАМИЧЕСКОМ ВЫДЕЛЕНИИ ПАМЯТИ В КЛАССАХ!!!!!!!!!
//  Иначе произойдет утечка памяти, тоесть она не уудалится сама, а потеряется после завершения работы

//  --------------------------Правила записи деструктора--------------------------------
//  1. Деструктор имеет такое же название как и класс, но имеет символ (" ~ " - тильда)
//  перед названием тоесть   ~Class
//  2.Не может принимать аргументы ---Тоесть для каждого класса существует только один деструктор---
//  3.Не имеет типа
//  ....................................................................................



//                        ------------------Пример кода----------------


//  class Massiv
//  {
//  private:
//	  int* m_array;   -размер 
//	  int m_length;   -длина
//
//  public:
//  	Massiv(int length) // конструктор   - пользователь вводит длину 
//  	{
//	    	assert(length > 0);  -проверка если length больше ноля
//
//	  	  m_array = new int[length];    - создается массив m_array размера length
//	  	  m_length = length;            - m_length присваивает значение length
//	    }
//
//	~Massiv() // деструктор
//	{
//		// Динамически удаляем массив, который выделили ранее
//		delete[] m_array; 
//	}
//    ------------присваивает переменной value значение индекса m_array-------------
//	  void setValue(int index, int value) { m_array[index] = value; } 

//    ------------выводит значение желаемого индекса--------------------------------
//	  int getValue(int index) { return m_array[index]; }
//    ----------выводит длину масива------------------------------------------------
//	  int getLength() { return m_length; }
//  };
//
//  int main()
//  {
//	  Massiv arr(15); // выделяем 15 целочисленных значений
//	  for (int count = 0; count < 15; ++count)
//		  arr.setValue(count, count + 1); 
//
//	  std::cout << "The value of element 7 is " << arr.getValue(7);  
//
//	  return 0;
//    } // объект arr удаляется здесь, поэтому деструктор ~Massiv() вызывается тоже здесь


//------------Пример работы деструктора--------------------


//  class Another
//  {
//  private:
//    int m_nID;     
//
//  public:
//    Another(int nID)
//    {
//        std::cout << "Constructing Another " << nID << '\n';
//        m_nID = nID;
//    }
//
//    ~Another()
//    {
//        std::cout << "Destructing Another " << m_nID << '\n';
//    }
//
//    int getID() { return m_nID; }
//  };
//
//  int main()
//  {
//    -----------------Выделяем объект класса Another из стека------------
//    Another object(1);
//    std::cout << object.getID() << '\n';
//
//   -----------Выделяем объект класса Another динамически из кучи------------
//    Another* pObject = new Another(2);
//    std::cout << pObject->getID() << '\n';
//    delete pObject;
//
//    return 0;
//   } // объект object выходит из области видимости здесь

//  ------------------Результат-----------------------------------------------


//  Constructing Another 1 - создался первый обьект в конструкторе
//  1                      - данный обьект
//  Constructing Another 2 -создался второй обьект в конструкторе
//  2                      - данный обьект
//  Destructing Another 2 -удалился второй обьект в деструкторе
//  Destructing Another 1 - удалился первый обьект в деструкторе



//  -------------------Скрытый указатель *this---------------------------------

//  При вызове метода класса, язык отслеживает обьект, который он вызвал,
//  с помощью скрытого указателя *this

//  class Another
//  {
//  private:
//      int m_number;   -переменная
//
//  public:
//      Another(int number)  -конструктор с параметром без значения по умолчанию = 3  (Another another(3);)
//      {
//          setNumber(number);  -вызов функции   ( another.setNumber(4);)   m_number = number = 4
//      }
//
//      void setNumber(int number) { m_number = number; } -функция принимающая значение number, и делится значением с m_number
//      int getNumber() { return m_number; }  -возвращает значение m_number
//  };
//
//  int main()
//  {
//      Another another(3);      -number = 3 
//      another.setNumber(4);    -функция приняла значение number = 4, и m_number взяла значение у number =4
//      std::cout << another.getNumber() << '\n';
//      return 0;
//  }

//       void setNumber(int number) { m_number = number; }
//      Компилируется компилятором как:
//        void setNumber(Another* const this, int number) { this->m_number = number; }


//  int main()
//  {
//    Another X(3); // *this = &X внутри конструктора Another
//    Another Y(4); // *this = &Y внутри конструктора Another
//    X.setNumber(5); // *this = &X внутри метода setNumber
//    Y.setNumber(6); // *this = &Y внутри метода setNumber
//
//    return 0;
//  }

//  ---Когда нужно использовать *this?----------
//  1. Если в конструкторе или методе в котором есть параметр(БЕЗ УКАЗАТЕЛЯ) с тем же именем что и 
//  переменная-член(С УКАЗАТЕЛЕМ), можно использовать чтобы понимать их
//
//  class Something
//  {
//  private:
//      int data;
//
//  public:
//      Something(int data)
//      {
//          this->data = data;
//      }
//  };   ---------Чтобы этого избегать можно просто использовать префикс " m_ "---------


//  ----------------------------Поэтапный разбор работы *this------------------

//  ----------------------------Программа без *this----------------------------
//  class Mathem
//  {
//  private:
//      int m_value;     -переменная
//
//  public:
//      Mathem() { m_value = 0; }  -конструктор присваивающий параметр m_value по умолчанию
//
//      void add(int value) { m_value += value; } - m_value+value=m_value (0+7=7)
//      void sub(int value) { m_value -= value; } - m_value-value=m_value (7-5=2)
//      void multiply(int value) { m_value *= value; } -m_value*value=m_value (2*3=6)
//
//      int getValue() { return m_value; }  -возвращает значение m_value = 6
//  };	

//  int main()
//  {
//    Mathem operation;
//    operation.add(7); // возвращает void   -присваивает переменной value значение 7
//    operation.sub(5); // возвращает void   -присваивает переменной value значение 5
//    operation.multiply(3); // возвращает void   -присваивает переменной value значение 3
//
//    std::cout << operation.getValue() << '\n';
//    return 0;
//  }

//--------------------------Программа с *this--------------------------------------------


//  class Mathem
//  {
//  private:
//      int m_value;-переменная
//
//  public:
//      Mathem() { m_value = 0; } -конструктор присваивающий параметр m_value = 0 по умолчанию
//
//      Mathem& add(int value) { m_value += value; return *this; }  - m_value+value=m_value (0+7=7) и возвращает указатель *this
//      Mathem& sub(int value) { m_value -= value; return *this; }  - m_value-value=m_value (7-5=2) и возвращает указатель *this
//      Mathem& multiply(int value) { m_value *= value; return *this; } -m_value*value=m_value (2*3=6) и возвращает указатель *this
//
//      int getValue() { return m_value; }
//  };


//  int main()
//  {
//      Mathem operation;
//      operation.add(7).sub(5).multiply(3); -т.к. каждая функция возвращает *this, который является ссылкой на  operation ,
//      то по сути можно сказать что это выражение имеет запись ((0 + 7) - 5) * 3), которое равно 6.
//
//      std::cout << operation.getValue() << '\n';
//      return 0;
//  }

// Таким образом, усли у вас есть функции, которые возвращают void, то возвращайте *this вместо void.
// Так вы сможете соединить несколько методов в одну «цепочку».
//  Это чаще всего используется при перегрузке операторов.
