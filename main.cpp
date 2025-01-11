#include <iostream>
#include <string>

// task 1
class Name
{
private:
  std::string last_name;
  std::string first_name;
  std::string father_name;
  std::string full_name;

  void fullarizeName()
  {
    full_name = "";

    if (last_name != "")
    {
      full_name += last_name;
      if (first_name != "")
      {
        full_name += " " + first_name;
        if (father_name != "")
        {
          full_name += " " + father_name;
        }
      }
      else
      {
        if (father_name != "")
        {
          full_name += " " + father_name;
        }
      }
    }
    else
    {
      if (first_name != "")
      {
        full_name += first_name;
        if (father_name != "")
        {
          full_name += " " + father_name;
        }
      }
      else
      {
        if (father_name != "")
        {
          full_name += father_name;
        }
      }
    }
  }

public:
  Name()
  {
    last_name = "";
    first_name = "";
    father_name = "";
  }

  Name(std::string lastName, std::string firstName, std::string fatherName)
  {
    last_name = lastName;
    first_name = firstName;
    father_name = fatherName;

    fullarizeName();
  }

  void print()
  {
    std::cout << full_name;
  }

  std::string lastName()
  {
    return last_name;
  }

  std::string firstName()
  {
    return first_name;
  }

  std::string fatherName()
  {
    return father_name;
  }

  std::string fullName()
  {
    return full_name;
  }
};

// task 2
class Human
{
private:
  Name name;
  int height;
  Human *father = NULL;

public:
  Human()
  {
    height = 0;
  }

  Human(std::string lastName, std::string firstName, std::string fatherName, int Height)
  {
    name = Name(lastName, firstName, fatherName);
    height = Height;
  }

  Human(Name nAme, int Height)
  {
    name = nAme;
    height = Height;
  }

  Human(std::string lastName, std::string firstName, std::string fatherName, int Height, Human *fAther)
  {
    name = Name(lastName, firstName, fatherName);
    height = Height;
    father = fAther;
  }

  Human(Name nAme, int Height, Human *fAther)
  {
    name = nAme;
    height = Height;
    father = fAther;
  }

  void print()
  {
    if (father == NULL)
    {
      name.print();
      std::cout << ", height: " << height;
    }
    else
    {
      if (name.lastName() != "")
      {
        std::cout << name.lastName();
        if (name.firstName() != "")
        {
          std::cout << " " << name.firstName();
          if (name.fatherName() != "")
          {
            std::cout << " " << name.fatherName();
          }
          else
          {
            if (father->humanName().firstName() != "")
            {
              std::cout << " " << father->humanName().firstName() << "ovich";
            }
          }
        }
        else
        {
          if (name.fatherName() != "")
          {
            std::cout << " " << name.fatherName();
          }
          else
          {
            if (father->humanName().firstName() != "")
            {
              std::cout << " " << father->humanName().firstName() << "ovich";
            }
          }
        }
      }
      else
      {
        if (father->humanName().lastName() != "")
        {
          std::cout << father->humanName().lastName();
          if (name.firstName() != "")
          {
            std::cout << " " << name.firstName();
            if (name.fatherName() != "")
            {
              std::cout << " " << name.fatherName();
            }
            else
            {
              if (father->humanName().firstName() != "")
              {
                std::cout << " " << father->humanName().firstName() << "ovich";
              }
            }
          }
          else
          {
            if (name.fatherName() != "")
            {
              std::cout << " " << name.fatherName();
            }
            else
            {
              if (father->humanName().firstName() != "")
              {
                std::cout << " " << father->humanName().firstName() << "ovich";
              }
            }
          }
        }
      }
      std::cout << ", height: " << height;
      std::cout << ", father: "; father->print();
    }
  }

  Name humanName()
  {
    return name;
  }

  int humanHeight()
  {
    return height;
  }
};

// task 3
class Town
{
private:
  std::string name;
  Town* towns[100] = {NULL};
  int prices[100] = {0};
public:
  Town(std::string nAme)
  {
    name = nAme;
  }

  void addTown(Town *newTown, int price)
  {
    int i;
    for (i = 0; i < 100; i++)
    {
      if (towns[i] == newTown)
      {
        return;
      }
      else
      {
        if (towns[i] == NULL)
        {
          break;
        }
      }
    }
    towns[i] = newTown;
    prices[i] = price;
    newTown->addTown(this, price);
  }

  std::string townName()
  {
    return name;
  }

  void print()
  {
    std::cout << "Town " << name;
    if (towns[0] != NULL)
    {
      std::cout << ", ways to other towns: ";
      for (int i = 0; i < 100; i++)
      {
        if (i == 0)
        {
          std::cout << towns[i]->townName() << ":" << prices[i];
        }
        else
        {
          if (towns[i] != NULL)
          {
            std::cout << ", " << towns[i]->townName() << ":" << prices[i];
          }
        }
      }
    }
  }
};

// task 4
class NameUpdated
{
private:
  std::string last_name;
  std::string first_name;
  std::string father_name;
  std::string full_name;

  void fullarizeName()
  {
    full_name = "";

    if (last_name != "")
    {
      full_name += last_name;
      if (first_name != "")
      {
        full_name += " " + first_name;
        if (father_name != "")
        {
          full_name += " " + father_name;
        }
      }
      else
      {
        if (father_name != "")
        {
          full_name += " " + father_name;
        }
      }
    }
    else
    {
      if (first_name != "")
      {
        full_name += first_name;
        if (father_name != "")
        {
          full_name += " " + father_name;
        }
      }
      else
      {
        if (father_name != "")
        {
          full_name += father_name;
        }
      }
    }
  }

public:
  NameUpdated()
  {
    last_name = "";
    first_name = "";
    father_name = "";
  }

  NameUpdated(std::string lastName, std::string firstName, std::string fatherName)
  {
    last_name = lastName;
    first_name = firstName;
    father_name = fatherName;

    fullarizeName();
  }

  NameUpdated(std::string lastName, std::string firstName)
  {
    last_name = lastName;
    first_name = firstName;
    father_name = "";

    fullarizeName();
  }

  NameUpdated(std::string firstName)
  {
    last_name = "";
    first_name = firstName;
    father_name = "";

    fullarizeName();
  }

  void print()
  {
    std::cout << full_name;
  }

  std::string lastName()
  {
    return last_name;
  }

  std::string firstName()
  {
    return first_name;
  }

  std::string fatherName()
  {
    return father_name;
  }

  std::string fullName()
  {
    return full_name;
  }
};

class HumanUpdated
{
private:
  NameUpdated name;
  int height;
  HumanUpdated *father = NULL;

public:
  HumanUpdated()
  {
    height = 0;
  }

  HumanUpdated(std::string lastName, std::string firstName, std::string fatherName, int Height)
  {
    name = NameUpdated(lastName, firstName, fatherName);
    height = Height;
  }

  HumanUpdated(NameUpdated nAme, int Height)
  {
    name = nAme;
    height = Height;
  }

  HumanUpdated(std::string firstName, int Height)
  {
    name = NameUpdated(firstName);
    height = Height;
  }

  HumanUpdated(std::string lastName, std::string firstName, std::string fatherName, int Height, HumanUpdated *fAther)
  {
    name = NameUpdated(lastName, firstName, fatherName);
    height = Height;
    father = fAther;
  }

  HumanUpdated(NameUpdated nAme, int Height, HumanUpdated *fAther)
  {
    name = nAme;
    height = Height;
    father = fAther;
  }

  HumanUpdated(std::string firstName, int Height, HumanUpdated *fAther)
  {
    name = NameUpdated(firstName);
    height = Height;
    father = fAther;
  }

  void print()
  {
    if (father == NULL)
    {
      name.print();
      std::cout << ", height: " << height;
    }
    else
    {
      if (name.lastName() != "")
      {
        std::cout << name.lastName();
        if (name.firstName() != "")
        {
          std::cout << " " << name.firstName();
          if (name.fatherName() != "")
          {
            std::cout << " " << name.fatherName();
          }
          else
          {
            if (father->humanName().firstName() != "")
            {
              std::cout << " " << father->humanName().firstName() << "ovich";
            }
          }
        }
        else
        {
          if (name.fatherName() != "")
          {
            std::cout << " " << name.fatherName();
          }
          else
          {
            if (father->humanName().firstName() != "")
            {
              std::cout << " " << father->humanName().firstName() << "ovich";
            }
          }
        }
      }
      else
      {
        if (father->humanName().lastName() != "")
        {
          std::cout << father->humanName().lastName();
          if (name.firstName() != "")
          {
            std::cout << " " << name.firstName();
            if (name.fatherName() != "")
            {
              std::cout << " " << name.fatherName();
            }
            else
            {
              if (father->humanName().firstName() != "")
              {
                std::cout << " " << father->humanName().firstName() << "ovich";
              }
            }
          }
          else
          {
            if (name.fatherName() != "")
            {
              std::cout << " " << name.fatherName();
            }
            else
            {
              if (father->humanName().firstName() != "")
              {
                std::cout << " " << father->humanName().firstName() << "ovich";
              }
            }
          }
        }
      }
      std::cout << ", height: " << height;
      std::cout << ", father: "; father->print();
    }
  }

  NameUpdated humanName()
  {
    return name;
  }

  int humanHeight()
  {
    return height;
  }
};

// task 5
class Cat
{
private:
  std::string name;
public:
  Cat()
  {
    name = "Cat";
  }

  Cat(std::string nAme)
  {
    name = nAme;
  }

  void print()
  {
    std::cout << "Cat: " << name;
  }

  void meow(int n = 1)
  {
    std::cout << name << ": ";
    for (int i = 0; i < n; i++)
    {
      if (i == 0)
      {
        std::cout << "meow";
      }
      else
      {
        std::cout << "-meow";
      }
    }
    std::cout << "!";
  }
};

int main()
{
  // task 1
  std::cout << "Task 1:\n\nClass Name\n";
  Name name;
  name = Name("", "Kleopatra", "");
  name.print();
  std::cout << std::endl;
  Name name1 = Name("Pushkin", "Aleksandr", "Sergeevich");
  name1.print();
  std::cout << std::endl;
  Name name2 = Name("Mayakovskiy", "Vladimir", "");
  name2.print();
  std::cout << std::endl;
  std::cout << std::endl;

  // task 2
  std::cout << "Task 2:\n\nClass Human\n";
  Human human = Human(name, 152);
  human.print();
  std::cout << std::endl;
  Human human1 = Human(name1, 167);
  human1.print();
  std::cout << std::endl;
  Human human2 = Human(name2, 189);
  human2.print();
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Class Human with a father\n";
  Human ivan = Human("Chudov", "Ivan", "", 180);
  Human petr = Human("Chudov", "Petr", "", 167, &ivan);
  Human boris = Human("", "Boris", "", 182, &petr);
  ivan.print();
  std::cout << "\n";
  petr.print();
  std::cout << "\n";
  boris.print();
  std::cout << std::endl;
  std::cout << std::endl;

  // task 3
  std::cout << "Task 3:\n\nClass Town\n";
  Town a = Town("A");
  Town b = Town("B");
  Town c = Town("C");
  Town d = Town("D");
  Town e = Town("E");
  Town f = Town("F");
  a.addTown(&b, 5);
  a.addTown(&d, 6);
  a.addTown(&f, 1);
  b.addTown(&c, 3);
  b.addTown(&f, 1);
  c.addTown(&d, 4);
  d.addTown(&e, 2);
  e.addTown(&f, 2);
  a.print();
  std::cout << "\n";
  b.print();
  std::cout << "\n";
  c.print();
  std::cout << "\n";
  d.print();
  std::cout << "\n";
  e.print();
  std::cout << "\n";
  f.print();
  std::cout << "\n\n";

  // task 4
  std::cout << "Task 4\n\nUpdated Name\n";
  NameUpdated name11 = NameUpdated("Kleopatra");
  NameUpdated name12 = NameUpdated("Pushkin", "Aleksandr", "Sergeevich");
  NameUpdated name13 = NameUpdated("Vladimir", "Mayakovskiy");
  NameUpdated name14 = NameUpdated("Hristofor", "Bonifatyevich");
  name11.print();
  std::cout << "\n";
  name12.print();
  std::cout << "\n";
  name13.print();
  std::cout << "\n";
  name14.print();
  std::cout << "\n\n";

  std::cout << "Updated Human\n";
  HumanUpdated lev = HumanUpdated("Lev", 170);
  NameUpdated sergei_name = NameUpdated("Pushkin", "Sergei");
  HumanUpdated sergei = HumanUpdated(sergei_name, 168, &lev);
  HumanUpdated aleks = HumanUpdated("Aleksandr", 167, &sergei);
  lev.print();
  std::cout << "\n";
  sergei.print();
  std::cout << "\n";
  aleks.print();
  std::cout << "\n\n";

  // task 5
  std::cout << "Task 5\n\nCat meows\n";
  Cat cat = Cat("Barsik");
  cat.print();
  std::cout << "\n";
  cat.meow();
  std::cout << "\n";
  cat.meow(3);
  std::cout << "\n\n";

  std::cin.get();
  return 0;
}
