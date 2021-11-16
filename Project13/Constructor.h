#pragma once
//  ............................������������...................................................

//  ��������� ���������������� ���������� ���������� �� ���������, ���� �������������, 
//  ��� �� ��������� ��������� ���� ��� ���� ������
//  1.�������� ������������ ������ ���� ��� � �������� ������
//  2.������������ ������������ ��� ���� ������, ������ �� ����� ��
//  ������������ !!������ ��� �������������!!
//



//  �lass Fraction
//  {
//  private:
//    int m_numerator;
//    int m_denominator;
//
//  public:
//    Fraction() // ����������� �� ��������� 
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
//    Fraction drob; // ��� ��� ��� ������� ����������, �� ���������� ����������� �� ��������� Fraction()

//    std::cout << drob.getNumerator() << "/" << drob.getDenominator() << '\n';
//  ---------------------��������� ����� 0/1, ������ �������� �� ���������------------------
//    return 0;
//  }



//  Fraction drob(4, 5); // �������������� ��������, ���������� ����������� Fraction(int, int)
//  ��������� 4/5

//  Fraction seven(7); // ���������� ����������� Fraction(int, int), ������ �������� ���������� �������� �� ���������
//  ������ �� �� ����� ��� Fraction drob(7, 1)
//  ��������� 7/1


//  ................... ������ ������������� ������ ������.............................................
//  �� ���� �� �� ����� ��� � ������������ �������� ����������, �� ������������� ��������� ����� ����������
//  � ����� ������������ �, � ������� ������ �������������, ��� ����� ������� ����� ������
//  ............................................................................................
//  RGBA(int red=0, int=0,int=0, int=255) - ���������� �� ��������� � ������������
//    : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha} - ������������� �������� ������ ������
//  ............................................................................................


//  ---------------------��� � �������������, �� ��������������-----------------------------------


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
//        // ��� �� �������� ������������, � �� �������������
//        m_value1 = 3;
//        m_value2 = 4.5;
//        m_value3 = 'd';
//    }
//  };


//  ---------------��� � ��������������, ��� ������ ������ �������������-------------------------	



//  class Values
//  {
//  private:
//    int m_value1;
//    double m_value2;
//    char m_value3;
//
//  public:
//    Values() : m_value1(3), m_value2(4.5), m_value3('d') // �������� �������������� ����������-����� ������
//    {
//        // ��� ������������� ������������ ������������
//    }
//
//    void print()
//    {
//        std::cout << "Values(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
//    }
//  };


//  -------------------------------����������� ������� �� �������������-----------------------------

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
//  ...................������������� ������������� �������� ������..........................
//  ������ �������� �� ���������, ������� ����� �������������� ������ ������� ��������������,
//  ��� ���� ������������ ����� �������� ���� ���������
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
//  ������� ������� ��������� �� ��������� ������� ����������
//	}
//
//	
//	Thing(const std::string& color):m_color(color)
//	{	
//  ������� �������� �������� color ������������� � �������� �� ��������� radius
//	}
//
//	
//	Thing(double radius):m_radius(radius)
//	{	
//  ������� �������� �������� radius ������������� � �������� �� ��������� color
//	}
//
//	
//	Thing(const std::string& color, double radius) :m_color(color),m_radius(radius)
//	{
//  ������� ��������� �������� �������������
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

//  ���������:
//  color: blue and radius : 20
//  color : red and radius : 20
//  color : blue and radius : 30
//  color : red and radius : 30



//  ........................................................................................
//  ...........................������������ ������������....................................
//  ������������ ����������-����������� ������� ����� �������� ������ �����������, ����� ��������� ���
//  ---���� ������������ ����������� ����� ������� ������ ���� ������ �����������
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
//    // ���������� ������������ ������������ ��� ���������� �������������� ����
//    Employee(const std::string& name) : Employee(0, name) { }
//  };

//  main

//  Employee a;
//  Employee b("Ivan");

//  ���������:

//  Employee a;
//   Employee  created.

//  Employee b("Ivan");
//  Employee Ivan created.



//  ....................................................................................
//  -----------------------------------�����������--------------------------------------

//  ������������ ���������� ��� ������������� ������� ������, ����������� �������� ��������,
//  ������ ������� ������, ����� �������� ������� ������ (�������� � ������������ �������)
//  !!!!!!!!!!!!!����������� ������������ ��� ������������ ��������� ������ � �������!!!!!!!!!
//  ����� ���������� ������ ������, ������ ��� �� ��������� ����, � ���������� ����� ���������� ������

//  --------------------------������� ������ �����������--------------------------------
//  1. ���������� ����� ����� �� �������� ��� � �����, �� ����� ������ (" ~ " - ������)
//  ����� ��������� ������   ~Class
//  2.�� ����� ��������� ��������� ---������ ��� ������� ������ ���������� ������ ���� ����������---
//  3.�� ����� ����
//  ....................................................................................



//                        ------------------������ ����----------------


//  class Massiv
//  {
//  private:
//	  int* m_array;   -������ 
//	  int m_length;   -�����
//
//  public:
//  	Massiv(int length) // �����������   - ������������ ������ ����� 
//  	{
//	    	assert(length > 0);  -�������� ���� length ������ ����
//
//	  	  m_array = new int[length];    - ��������� ������ m_array ������� length
//	  	  m_length = length;            - m_length ����������� �������� length
//	    }
//
//	~Massiv() // ����������
//	{
//		// ����������� ������� ������, ������� �������� �����
//		delete[] m_array; 
//	}
//    ------------����������� ���������� value �������� ������� m_array-------------
//	  void setValue(int index, int value) { m_array[index] = value; } 

//    ------------������� �������� ��������� �������--------------------------------
//	  int getValue(int index) { return m_array[index]; }
//    ----------������� ����� ������------------------------------------------------
//	  int getLength() { return m_length; }
//  };
//
//  int main()
//  {
//	  Massiv arr(15); // �������� 15 ������������� ��������
//	  for (int count = 0; count < 15; ++count)
//		  arr.setValue(count, count + 1); 
//
//	  std::cout << "The value of element 7 is " << arr.getValue(7);  
//
//	  return 0;
//    } // ������ arr ��������� �����, ������� ���������� ~Massiv() ���������� ���� �����


//------------������ ������ �����������--------------------


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
//    -----------------�������� ������ ������ Another �� �����------------
//    Another object(1);
//    std::cout << object.getID() << '\n';
//
//   -----------�������� ������ ������ Another ����������� �� ����------------
//    Another* pObject = new Another(2);
//    std::cout << pObject->getID() << '\n';
//    delete pObject;
//
//    return 0;
//   } // ������ object ������� �� ������� ��������� �����

//  ------------------���������-----------------------------------------------


//  Constructing Another 1 - �������� ������ ������ � ������������
//  1                      - ������ ������
//  Constructing Another 2 -�������� ������ ������ � ������������
//  2                      - ������ ������
//  Destructing Another 2 -�������� ������ ������ � �����������
//  Destructing Another 1 - �������� ������ ������ � �����������



//  -------------------������� ��������� *this---------------------------------

//  ��� ������ ������ ������, ���� ����������� ������, ������� �� ������,
//  � ������� �������� ��������� *this

//  class Another
//  {
//  private:
//      int m_number;   -����������
//
//  public:
//      Another(int number)  -����������� � ���������� ��� �������� �� ��������� = 3  (Another another(3);)
//      {
//          setNumber(number);  -����� �������   ( another.setNumber(4);)   m_number = number = 4
//      }
//
//      void setNumber(int number) { m_number = number; } -������� ����������� �������� number, � ������� ��������� � m_number
//      int getNumber() { return m_number; }  -���������� �������� m_number
//  };
//
//  int main()
//  {
//      Another another(3);      -number = 3 
//      another.setNumber(4);    -������� ������� �������� number = 4, � m_number ����� �������� � number =4
//      std::cout << another.getNumber() << '\n';
//      return 0;
//  }

//       void setNumber(int number) { m_number = number; }
//      ������������� ������������ ���:
//        void setNumber(Another* const this, int number) { this->m_number = number; }


//  int main()
//  {
//    Another X(3); // *this = &X ������ ������������ Another
//    Another Y(4); // *this = &Y ������ ������������ Another
//    X.setNumber(5); // *this = &X ������ ������ setNumber
//    Y.setNumber(6); // *this = &Y ������ ������ setNumber
//
//    return 0;
//  }

//  ---����� ����� ������������ *this?----------
//  1. ���� � ������������ ��� ������ � ������� ���� ��������(��� ���������) � ��� �� ������ ��� � 
//  ����������-����(� ����������), ����� ������������ ����� �������� ��
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
//  };   ---------����� ����� �������� ����� ������ ������������ ������� " m_ "---------


//  ----------------------------��������� ������ ������ *this------------------

//  ----------------------------��������� ��� *this----------------------------
//  class Mathem
//  {
//  private:
//      int m_value;     -����������
//
//  public:
//      Mathem() { m_value = 0; }  -����������� ������������� �������� m_value �� ���������
//
//      void add(int value) { m_value += value; } - m_value+value=m_value (0+7=7)
//      void sub(int value) { m_value -= value; } - m_value-value=m_value (7-5=2)
//      void multiply(int value) { m_value *= value; } -m_value*value=m_value (2*3=6)
//
//      int getValue() { return m_value; }  -���������� �������� m_value = 6
//  };	

//  int main()
//  {
//    Mathem operation;
//    operation.add(7); // ���������� void   -����������� ���������� value �������� 7
//    operation.sub(5); // ���������� void   -����������� ���������� value �������� 5
//    operation.multiply(3); // ���������� void   -����������� ���������� value �������� 3
//
//    std::cout << operation.getValue() << '\n';
//    return 0;
//  }

//--------------------------��������� � *this--------------------------------------------


//  class Mathem
//  {
//  private:
//      int m_value;-����������
//
//  public:
//      Mathem() { m_value = 0; } -����������� ������������� �������� m_value = 0 �� ���������
//
//      Mathem& add(int value) { m_value += value; return *this; }  - m_value+value=m_value (0+7=7) � ���������� ��������� *this
//      Mathem& sub(int value) { m_value -= value; return *this; }  - m_value-value=m_value (7-5=2) � ���������� ��������� *this
//      Mathem& multiply(int value) { m_value *= value; return *this; } -m_value*value=m_value (2*3=6) � ���������� ��������� *this
//
//      int getValue() { return m_value; }
//  };


//  int main()
//  {
//      Mathem operation;
//      operation.add(7).sub(5).multiply(3); -�.�. ������ ������� ���������� *this, ������� �������� ������� ��  operation ,
//      �� �� ���� ����� ������� ��� ��� ��������� ����� ������ ((0 + 7) - 5) * 3), ������� ����� 6.
//
//      std::cout << operation.getValue() << '\n';
//      return 0;
//  }

// ����� �������, ���� � ��� ���� �������, ������� ���������� void, �� ����������� *this ������ void.
// ��� �� ������� ��������� ��������� ������� � ���� ��������.
//  ��� ���� ����� ������������ ��� ���������� ����������.
