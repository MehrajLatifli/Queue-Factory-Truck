#include <iostream>
#include <assert.h>


using namespace std;

template<typename T>
class Queue {
	T* data;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue() {}
	Queue(int size) {
		data = new T[size];
		capacity = size;
		front = 0;
		rear = 0;
		count = 0;
	}

	void enqueue(T value) {
		assert(!isFull() && " Queue is full ");
		data[rear] = value;
		++rear;
		count++;
	}



	void dequeue() {
		if (!isEmpty()) {
			auto temp = new T[size() - 1];
			for (size_t i = 0; i < count - 1; i++)
			{
				temp[i] = data[i + 1];
			}
			delete[]data;
			data = temp;
			temp = nullptr;
			count--;
		}
	}

	T& peek() {
		return data[front];
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return size() == 0;
	};

	bool isFull() {
		return size() == capacity;
	}

	~Queue()
	{
		//Copy asigment yazilmalidir.

		/*if (data != nullptr) {
			delete[]data;
			data = nullptr;
		}*/
	}




};


class Product {
	int myid;
	string name;
	double price;
	double discount;
public:
	static int id;
	Product() {};
	Product(const string& name, const double& price, const double& discount) {
		setName(name);
		setPrice(price);
		setDiscount(discount);
		myid = ++id;
	}

	Product& operator= (const Product& other) {
		setName(other.name);
		setPrice(other.price);
		setDiscount(other.discount);
		myid = other.myid;
		return *this;
	}

	string getName() {
		return name;
	}

	double  getPrice() {
		return price;
	}

	double  getDiscount() {
		return discount;
	}

	void setName(const string& name) {
		this->name = name;
	}

	void setPrice(const double& price) {
		this->price = price;
	}

	void setDiscount(const double& discount) {
		this->discount = discount;
	}

	void show() {
		cout << "\n Id: " << myid << endl;
		cout << " Name: " << getName() << endl;
		cout << " Price: " << getPrice() << endl;
		cout << " Discount: " << getName() << endl;
		cout << " ================================== " << endl;
	}

};

int  Product::id = 0;

void main() {

	Product p1("Samsung A70", 1000, 10);
	Product p2("Samsung A50", 600, 10);
	Product p3("Samsung A40", 400, 10);
	Product p4("Samsung A10", 250, 10);

	Queue<Product> tir1(2);
	Queue<Product> tir2(2);

	tir1.enqueue(p1);
	tir1.enqueue(p2);
	tir2.enqueue(p3);
	tir2.enqueue(p4);


	Queue<Queue<Product>> factory(2);
	factory.enqueue(tir1);
	factory.enqueue(tir2);

	while (!factory.isEmpty()) {
		Queue<Product> tir = factory.peek();
		while (!tir.isEmpty()) {
			Product product = tir.peek();
			product.show();
			tir.dequeue();
		}
		factory.dequeue();
	}

}