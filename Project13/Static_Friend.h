#pragma once
// ------------------��������� ���������� �� ����������------------------

// ����� � ������ ���������� ������� ��������� ������� ��������, ����� 
// �������� ������� � ������ � ����������� �� �������

// -----------------------������ ����-----------------------------
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
//  // ����������� ������ Date 
//  Date::Date(int day, int month, int year)
//  {
//     SetDate(day, month, year);
//  }
//
//  // ����� ������ Date 
//  void Date::SetDate(int day, int month, int year)
//  {
//      m_day = day;
//      m_month = month;
//      m_year = year;
//  }


// --------������ ���� �� ������� �������������-----------------



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


// !!!!!���������� ������� ����� ��������� � ������ ������������ ������, 
// ������ �������� � ����� � �������, � ����������� � ������ ����� ��� ������

// -------------  Const � �������--------------------------------------------

// const int value1 = 6; // ���������� �������������
// const int value2(8); // ������ �������������
// const int value3{ 11 }; // uniform-������������� (C++11)

// ����� ��� ������, ��� ������ � ������ ����� ������� �����������,
// � ����������� ��������� ������ ����� �������� ��� ���������, ��� ������� ��������� �������, ����� ������


//  -------������ ������ ��� ��������� ���������-----------------------------
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
//     const Anything anything; // �������� ����������� �� ���������
//
//     anything.m_value = 7; // ������ ����������: ��������� const
//     anything.setValue(7); // ������ ����������: ��������� const
//
//     return 0;
// }


// ------------����������� ������ �������-----------------------------


// ���������� ������ � ����� ��� ����������� ����:
//     std::cout << anything.getValue();


// ����� �� ����� ��������, ���� ��� ������� ��������� �����, ����� ������ ��� ���������, 
// ����� �������� ��� ����� �����������, ������ � ��������� ������� ����� ������� ���������


//  -------------------������------------------------------------------


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
//     int getValue() const { return m_value; } // �������� ����� const ��������� ����� ������ ����������, �� ����� ����� �������
// };


// ��� ��������� ������� ��� �� ����� ����������� ���������, ��������:


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
//     int getValue() const;                 - �������� �������� �� �������� ����� const �����
// };
//
// int Anything::getValue() const            - � �����
// {
//     return m_value;
// }


// !!!!!!!������������ �� ����� ���� ������������!!!!!!!!!!!
// ������������� ������ ��� ������, ������� �� �������� ������ ������������


//  ��������� �� �� ����� �������� ������������� ������ ����� ����������� �������,
//  ����� ������ �������� ������������


// ------------------------------����������-------------------------------------------
//  ����� �����, ������� �� �������� ������ ������� ������, ������ ���� const!


// ------------------����������� ����������-����� ������-----------------------------

// ����������� ���������� ��� ���������� ������� ����� ������ �� �����, � ������� ��� ���������,
// ��������� ���� ��������, ��������:

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


// ���������:   1   2   3 


// ��� ��� ������������� ���������� ���������� - ��� ���, ����� ������������ ������� ��������� 
// ����������� ����������, � ���� ������� �������� ����� --static--


//  ���������� ���:


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


// ���������: 4
//            3


// !!! ��� ��� ��� �������� ������� ������, ��������� ��� ����������� ����� ���� ���������� ������, 
// � ���� ������� �� �������� ��� ������� ������ Anything, � ��� ����� ��� ����� m_value: first.m_value � second.m_value
// ��� ��� ��� ������ ��������, ��������� 4 � 3


// ���������� ������ ���:


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

// ���������: 4
//            4 

// ��� ��� �� �������� ���������� --s_value-- �����������, ��� �������� ����� ��� ���� ��������, 
// ������������� first.m_value � second.m_value, ��� ���� � �� �� ����������, ������� ����� ������ ������,
// �� ����� �������� ������ ������


// ����������� ����� �� ������� � ��������� ������, ������ ����������� ���������� ��������� � ������ ������
// ���������, � ��������� � ����� ������ ���������, ������ ����������� ������, � �� �������� ������, 
// � ������� �� ����� ������� ��� ���������� ����� ��� ������, � �������� ���������� ������� ���������(::)

// ������:     Anything::s_value;

// ����������� � ������������� ����������� ����������-������ ������


// ��� ���������� ����������� ���������� ������ ������, �� �������� ����������� � �������������
// ����������� ����������, �� �� � � �����������. ��������� ����������� ���������� �� �������� 
// ������ ���������� ������� ������, �� ������ ���� ���������� ����������� ���� ��� ������, � ���� ���� 
// ��� ������:		int Anything::s_value = 3; // ���������� ����������� ����������-����
// ������ �� ���������� ����������� ����������, � ���� �� �������� 3, ���� �� �� ����� �� �������, �� 
// ���������� �������� �� ���������� s_value �������� 0

// ����������� ���������� �� �������� ��� public, private, protected

//  ������������� ����������� ���������� - ������ ������ ���� ������

// ���� ����������� ����������-���� �������� �����������, � ����� ���������������� � ���� ������, ��������:

// class Anything
// {
// public:
//     static const int s_value = 5; // ����������� ����������� ���������� ���� int ����� �������� � ���������������� ��������
// };

// ������������� ���� �������:



// class Anything
// {
// private:
//     static int s_idGenerator;
//     int m_id;
//
// public:
//     Anything() { m_id = s_idGenerator++; } --- ����������� �������� �������������� ��� ���������� �������
//
//     int getID() const { return m_id; }
// };
//
//   ----�� ���������� � �������������� s_idGenerator �������� �� ��, ��� �� �������� ��� private.
//   ----��� ���������, ��������� ����������� �� ��������� ��� �������� �������������� �������
// int Anything::s_idGenerator = 1; ---- �������� ��� ID-��������� �� �������� 1
//
// int main()
// {
//     Anything first;
//     Anything second;
//     Anything third;
//
//     std::cout << first.getID() << '\n';    ���������: 1
//     std::cout << second.getID() << '\n';   ���������: 2
//     std::cout << third.getID() << '\n';    ���������: 3
//     return 0;
// }



//  -----------����������� ������ ������--------------------------------

// ����������� ���������� ��� ����� ������� ����������� ������, � �� ��� ��������


// ����������� ����������, �������� ���������, �� ��� ���� ��� ����� ���������, ��������:

// class Anything
// {
// private:
//     static int s_value;
//
// };
//
// int Anything::s_value = 3; // ����������� ������������ �����, �������� �� ��, ��� �� �������� private
//
// int main()
// {
//     // ��� �������� ������ � Anything::s_value �����, ���� s_value �������� private?
// }


// ��� ������� ���� ��������� ����� ������� ����������� �����, ������:


// class Anything
// {
// private:
//     static int s_value;
// public:
//     static int getValue() { return s_value; } // ����������� �����
// };
//
// int Anything::s_value = 3; // ����������� ����������� ����������-����� ������
//
// int main()
// {
//     std::cout << Anything::getValue() << '\n';
// }


// � ����������� ������� ���� �����������:


// 1.��� ��� ����������� ������ �� ��������� � �������, � ��� ��� ��������� (*this)
// 2. ���������� ������ ����� �������� �������� �� ������������ �����������,
// �� �� ����� �������� � �������������� �����������, ���� ����, ��� ������������� ���������� 
// ����������� ������� ������, � ����������� ������ - ���!!

//����������� ������ ����� ���������� ��� ������, ��������:


//  class IDGenerator
//  {
//  private:
//      static int s_nextID; ----���������� ����������� ����������-�����
//
//  public:
//      static int getNextID();  ----���������� ������������ ������
//  };
//
//  ----����������� ����������� ����������-����� ��������� ��� ���� ������. �������� ��������, �� �� ���������� ����� �������� ����� static.
//  ----�������� ������������ ID � 1
//  int IDGenerator::s_nextID = 1;
//
//  -----����������� ������������ ������ ��������� ��� ���� ������. �������� ��������, �� �� ���������� ����� �������� ����� static
//  int IDGenerator::getNextID() { return s_nextID++; }
//
//  int main()
//  {
//      for (int count = 0; count < 4; ++count)
//          std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';
//
//      return 0;
//  }


//  ���������:

// The next ID is : 1
// The next ID is : 2
// The next ID is : 3
// The next ID is : 4

// ��� ��� ��� ���������� � ������� ����� ������ �������� ������������, ��� �� ����� ��������� ������ 
// ����� ������ ��� ������ � ���!!!


// !!!!�������������� � ������� �� ����� ������������ �������!!!!!!!!!!

// 1. ��� ��� ��� ����������� ����� ��������� ������ 1 ���, �� ��������� ����� ����� ������ ���� �� �����,
// ��������: ���� ��� ����� 2 ����������� ������� ������ Class, �� ��� ����� ����������� 
// 2. ����������� ������ �������� �����������, ��� ���������� �� ����� �������� ���������� ����������, 
// �� ���� ��������� ������ �����, ������� ����� �������� ���� ���	



//  ��� ������������� ����������� ����������-�����(����) ������:


//  class Something
//  {
//  private:
//	static std::vector<char> s_mychars;
//
//  public:
//  	class _nested ----- ���������� ��������� ����� � ������ _nested
//	  {
//	  public:
//		  _nested() ----- ����������� _nested() �������������� ���� ����������� ����������-����
//		  {
//			  s_mychars.push_back('o');
//			  s_mychars.push_back('a');
//	       	  s_mychars.push_back('u');
//	  	  	  s_mychars.push_back('i');
//			  s_mychars.push_back('e');
//		  }
//	  };
//
//	  // ����������� ����� ��� ������ s_mychars
//	  static void getSomething() {
//		  for (auto const& element : s_mychars)
//			  std::cout << element << ' ';
//	  }
//  private:
//	  static _nested s_initializer; ----���������� ����������� ������ ������ _nested ��� �������� ����, ��� ����������� _nested() ����������
//  };
//
//  std::vector<char> Something::s_mychars; ---- ���������� ���� ����������� ����������-����
//  Something::_nested Something::s_initializer; ----- ���������� ��� ����������� s_initializer, ������� ������� ����������� _nested() ��� ������������� s_mychars
//
//  int main() {
//  	Something::getSomething();
//  	return 0;
//  }


//  ���������: o a u i e


// ����������:
// ����������� ������ ����� �������������� ��� ������ �� ������������ �����������-������� ������.
// ��� ������ � ���� �� ��������� ��������� ������� ������.




// ---------------������������� ������� � ������----------------------------------

// ������������� ������� ����� ��� ������� � �������� ������ ������, �� �� ����� ��� ���� �� ��� ���� 
// ���� ������ ����� ������. �� ���� ��� ������� �������

//  ��� ���������� ������������� ������� ������������ �������� ����� ---friend---- ����� ���������� �������, 
//  ������� �� ������ ������� ������������� ������. 


//  class Anything
//  {
//  private:
//      int m_value;
//  public:
//      Anything() { m_value = 0; }
//      void add(int value) { m_value += value; }
//
//      ---- ������ ������� reset() ������������� ������ Anything
//      friend void reset(Anything& anything);
//  };
//
//  ------ ������� reset() ������ �������� ������ ������ Anything
//  void reset(Anything& anything)
//  {
//      ------ � �� ����� ������ � �������� ������ �������� ������ Anything
//      anything.m_value = 0;
//  }
//
//  int main()
//  {
//      Anything one;
//      one.add(4); ------ ��������� 4 � m_value
//      reset(one); ------ ���������� m_value � 0
//
//      return 0;
//  }


//  ----������� ����� ���� ������������� ����� ��� ���������� �������, ��������:


//  class Humidity;  ----�������� ������
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


// ---------���� ����� ����� ���� ������������� ������� ������--------------

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
//      -------- ������ ����� Display ������ ������ Values
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
//          else ------ ��� ������� ������� double
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

// ���������: 8.4  7


// !!!!!  ����������  !!!!!

// 1. ������������� ������ �� ����� ������ ��������� *this  ���� �����
// 2. ���� ����� 1 �������� ������ ������ 2, �� ��� �� ������ ��� ����� 2 �������� ������ ������ 1
// ������ ����� ������� � ����� ������� ���������������



// ------------������������� ������---------------



//class Display; // ��������������� ���������� ������ Display
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
//	// ������ ����� Display::displayItem() ������ ������ Values
//	friend void Display::displayItem(Values& value); // ������: Values �� ����� ������� ����������� ������ Display
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
//		else // ��� ������� ������� double
//			std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//	}
//};


// �� ��� �� ���������� �����, ��� ��� ���������� ������ ������� ������ ����������� ������, 
// � ������� ������������� ����� ������������ (� �� ������ ���� ��� ��������).
// ��������� ����������, ���������� ��������������� ������� ���� �� ������ ������� ����������� ������ Display,
// �� ����� ������� �������� ��� ������, �� �� ������ ������ � ������ ����������� ����� ������ ������������� ������ Values (������ �16).



// ����� ���������� ����������� ����������� ������  Display ���� ����������� ������� ������



//class Display
//{
//private:
//	bool m_displayIntFirst;
//
//public:
//	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//	void displayItem(Values& value) // ������: ���������� �� �����, ��� ����� Values
//	{
//		if (m_displayIntFirst)
//			std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//		else // ��� ������� ������� double
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
//	// ������ ����� Display::displayItem() ������ ������ Values
//	friend void Display::displayItem(Values& value);
//};



// ��������� ����� Display::displayItem() ���������� ������ �� ������ ������ Values � �������� ���������,
// � �� ������ ��� ��������� ����������� Display ���� ����������� Values, �� ���������� ����� ����������,
// ��� �� �� �����, ��� ����� Values. ���������� ��������� ����.

// ������� �������:

// 1.��� ������ Values ���������� ��������������� ����������.
// 2.��������� ����������� ������ Display::displayItem() �� ������� ������ Display,
// � ��������� ��� ����� ������� ����������� ������ Values.



//class Values; // ��������������� ���������� ������ Values
//
//class Display
//{
//private:
//	bool m_displayIntFirst;
//
//public:
//	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//	void displayItem(Values& value); // ��������������� ����������, ����������� ����, ��������� ��� ���� ������
//};
//
//class Values // ������ ����������� ������ Values
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
//	// ������ ����� Display::displayItem() ������ ������ Values
//	friend void Display::displayItem(Values& value);
//};
//
//// ������ �� ����� ���������� ����� Display::displayItem(), �������� ��������� ������� ������ ����������� ������ Values
//void Display::displayItem(Values& value)
//{
//	if (m_displayIntFirst)
//		std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//	else // ��� ������� ������� double
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


// ������ �� �������� ���������, �� ��� ����� ������ �������� 
//  ���� ��������� ��� ������ � ������ ������������ ����� � ������������ �������


//----------������� �� ��������----------------------------



//class Vector3D; // ������� ������� �����������, ��� ����� � ������ Vector3D ����������
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
//	void moveByVector(const Vector3D& v); // ����� �� ����� ������������ Vector3D �����
//	   // ����������: �� �� ����� ���������� ��� ������� �����, ��� ��� Vector3D ��� �� ��� ��������� (���������� ������ ������ ��� ��������������� ����������)
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
//	friend void Point3D::moveByVector(const Vector3D& v); // Point3D::moveByVector() ������ �������� ������ ������ Vector3D
//};
//
//// ������, ����� Vector3D ��� ���������, �� ����� ���������� ������� Point3D::moveByVector()
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

