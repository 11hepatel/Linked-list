
//Function to set my_id to MST id
void get_identity(std::string &my_id)
{
  my_id = "hdpg4c";
}

//Function to make a sentinel node
template <typename T>
MyList<T>::MyList()
{
  //one sentinel node
  m_sentinel = new Node<T>(nullptr, nullptr);
  m_sentinel->m_next = m_sentinel; //node pointer
  m_sentinel->m_prev = m_sentinel;
  m_size = 0; //size set to 0
}

//destructor
template <typename T>
MyList<T>::~MyList()
{
  if(size() > 0) //if size is greater than 0
  {
    Node<T> *array; //decleration of pointer of node type
    array = m_sentinel; //pointer set to m_sentinel
    if(array->m_next != nullptr) //checks if array-next is not equal to null
    {
      array = m_sentinel->m_next;
      for(int i = 0; i < m_size; i++)
      {
        array->m_next->m_prev = m_sentinel; //set to m_sentinel
        m_sentinel->m_next = array->m_next;
        delete array; //deletes the array
        array = m_sentinel->m_next;//sets array to next sentinel 
      }
    }
    delete m_sentinel;//deletes the m_Sentinel pointer
  }
  else
    delete m_sentinel; //deleted the m_sentinel pointer
}

//Overloading operator //deep copy
template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
  clear(); //calls the clear function

  Node<T> *array = source.m_sentinel;//set a new pointer to source m_sentinel
  for(int i = 0; i < source.m_size; i++)//for not equal to m_sentinedl pointer
  {
    array = array->m_next; //array set to next index
    push_back(array->m_element); //calls the push back function
  }
  return *this;
}

//copy constructor 
template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
  m_size = 0; //size is set to 0
  m_sentinel = nullptr; //m_sentinel node pointer set to nullptr

  m_sentinel = new Node<T>(nullptr, nullptr); 
  Node<T> *array = source.m_sentinel; //new node type pointer set to source

  for(int i = 0; i < source.m_size; i++)
  {
    array = array->m_next;
    push_back(array->m_element); //calls the push back function
  }
}

//Function to return the element stored at the front of list
template <typename T>
T & MyList<T>::front()
{
  return m_sentinel->m_next->m_element;
}

//Function to return the element stored at the back of list
template <typename T>
T & MyList<T>::back()
{
  return m_sentinel->m_prev->m_element;
}

//Fills array with count of T value
template <typename T>
void MyList<T>::assign(int count, const T &value)
{
  //pop_back is called while m_size
  while(m_size)
    pop_back();

  for(int i = 0; i < count; i++)
    push_back(value);
  m_size = count; //size is set to the count
}

//Function to clear the list
template <typename T>
void MyList<T>::clear()
{
  while(m_size)
    pop_back();
}

//Function to append the value x to the front of MyList
template <typename T>
void MyList<T>::push_front(const T &x)
{
  //checks if the next and prev sentinel are equal to null 
  //checks if empty
  if((m_sentinel->m_next == nullptr) && (m_sentinel->m_prev == nullptr))
  {
    Node<T> *temp = new Node<T>(x,m_sentinel,m_sentinel);//new pointer
    m_sentinel->m_next = temp; //next element is equal to temp
    m_sentinel->m_prev = temp; //prev element equal to temp
    m_size++; //increments the size by 1
  }
  else //if next and prev sentinel are not equal to null //not empty
  {
    Node<T> *array = new Node<T>(x, m_sentinel, m_sentinel->m_next);
    m_sentinel->m_next->m_prev = array;
    m_sentinel->m_next = array;
    m_size++; //increments the size by 1
  }
  return;
}

//Function to appends the value x to the end of an MyList
template <typename T>
void MyList<T>::push_back(const T &x)
{
   //checks if the next and prev sentinel are equal to null
  if((m_sentinel->m_next == nullptr) && (m_sentinel->m_prev == nullptr))
  {
    Node<T> *temp = new Node<T>(x,m_sentinel,m_sentinel);
    m_sentinel->m_next = temp;
    m_sentinel->m_prev = temp;
    m_size++; //incremnts the size
  }
  else //if next and prev sentinel are not equal to null
  {
    Node<T> *array = new Node<T>(x, m_sentinel->m_prev, m_sentinel);
    m_sentinel->m_prev = array;
    array->m_prev->m_next = array;
    m_size++; //increments the size
  }

  return;
}

//Function removes the last element of the list
template <typename T>
void MyList<T>::pop_back()
{
  Node<T> *array = m_sentinel->m_prev;
  m_sentinel->m_prev = array->m_prev;
  array->m_prev->m_next = m_sentinel;

  delete array; //free the memory
  m_size--; //decrements the size by 1
}

//Function removes the front element of the list
template <typename T>
void MyList<T>::pop_front()
{
  Node<T> *array = m_sentinel->m_next;
  m_sentinel->m_next = array->m_next;
  array->m_next->m_prev = m_sentinel;
  delete array; //free the memory
  m_size--; //decrements the size by 1
}

//Function to insert the value x at the position i
template <typename T>
void MyList<T>::insert(int i, const T &x)
{
  if (!empty()) //if size is not equal to 0
  {	
    Node<T> *array = m_sentinel; //node type pointer 
    array = array->m_next;
    for(int j = 0 ; j < i && i < size(); j++) //iterated till j is less then i
                                              //and i is less then size
    {  
      array = array->m_next; 
    }
    
    Node<T> *new_array = new Node<T>(x, array->m_prev, array);
    array->m_prev->m_next = new_array;
    array->m_prev = new_array;

    m_size++; //increments the size by 1
  }
  else
    push_back(x);

  return;
}

//Function removes all elements in the list that are equal to value
template <typename T>
void MyList<T>::remove(T value)
{
  if(!empty())
  {
    Node<T> *temp = m_sentinel->m_next;
    Node<T> *array;
    
    for(int i = 0; i < m_size; i++)//temp not equal to sentinel
    {
      if(temp->m_element == value) //if element equal to value
      {
        array = temp; //array equal to node pointer
        array->m_next->m_prev = array->m_prev;
        array->m_prev->m_next = array->m_next;
        delete array; //free the memory
        temp = temp->m_next;
        m_size--; //decrements the size
      }
      else 
        temp = temp->m_next; //next element
    }
  }
}

//Function to remove element at certain position i
template <typename T>
void MyList<T>::erase(int i)
{
  Node<T> *temp = m_sentinel;
  temp = temp->m_next;

  for(int j = 0; j < i; j++)
    temp = temp->next; //element at certain position

  temp->m_next->m_prev = temp->m_prev;
  temp->m_prev->m_next = temp->m_next;
    
  delete temp; //deletes the temp array
   
  m_size--;//decrements the size by 1
  return;
}

//Function to crete space fpr elements 
template <typename T>
void MyList<T>::reverse()
{
  if(!empty()) //size is not equal to 0
  {
    Node<T> *temp = m_sentinel->m_prev;
    Node<T> *array = m_sentinel->m_next;

    for(int i = 0; i < (m_size/2); i++)
    {
      std::swap(array->m_element, temp->m_element); //calls the swap function
      array = array->m_next;
      temp = temp->m_prev;
    }
  }
}

//returns a bool and check if empty
template <typename T>
bool MyList<T>::empty()
{
  //if size equal to 0, then return true
  if(m_size == 0)
    return true;

  return false;
}

//Function returns the size 
template <typename T>
int MyList<T>::size()
{
  return m_size;
}
