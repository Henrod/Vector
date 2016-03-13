#include <stdexcept>

class Vector {
	public:
		Vector			(const int size = 1);
		virtual ~Vector		();
		void 	insert		(const int& data);
		int 	operator[]	(const int& i) const throw (std::out_of_range);
		int 	remove		(const int& i) throw(std::out_of_range);
		void 	print		() const;
	private:
		void 	checkBoundary	(const int& i) const throw (std::out_of_range);
		void 	slide		(const int& i);
		void 	copy		(const int& capacity);
		int 	mSize;
		int 	mCapacity;
		int* 	mVector;
};
