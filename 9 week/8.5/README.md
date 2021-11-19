# 8.5

> 온라인 북 리더(Online Book Reader)에 대한 자료구조를 설계하라.

박수원
<details> 
<summary> 접기/펼치기 버튼 </summary>  

```java
/**
 *  AppTest.java
 *
 *
 *  예상 요구사항
 *    사용자 가입 정보 생성 및 확장
 *    서적 데이터베이스 검색
 *    책 읽기
 *    한번에 한 명의 사용자만 활성화 된 상태
 *    활성화 된 사용자가 읽는 한 권의 책만 활성화 상태
 */

import java.util.HashMap;

class OnlineReaderSystem {
	private Library library;
	private UserManager userManager;
	private Display display;
	private Book activeBook;
	private User activeUser;

	public OnlineReaderSystem()
	{
		userManager = new UserManager();
		library = new Library();
		display = new Display();
	}

	public Library getLibrary()
	{
		return library;
	}

	public UserManager getUserManager()
	{
		return userManager;
	}

	public Display getDisplay()
	{
		return display;
	}

	public Book getActiveBook()
	{
		return activeBook;
	}

	public void setActiveBook(Book book)
	{
		activeBook = book;
		display.displayBook(book);
	}

	public User getActiveUser()
	{
		return activeUser;
	}

	public void setActiveUser(User user)
	{
		activeUser = user;
		display.displayUser(user);
	}
}

/*
* This class represents the Library which is responsible
* for storing and searching the books.
*/
class Library {
	private HashMap<Integer, Book> books;

	public Library()
	{
		books = new HashMap<Integer, Book>();
	}

	public Boolean addBook(int id, String details, String title)
	{
		if (books.containsKey(id)) {
			return false;
		}
		Book book = new Book(id, details, title);
		books.put(id, book);
		return true;
	}

	public Boolean addBook(Book book)
	{
		if (books.containsKey(book.getId())) {
			return false;
		}

		books.put(book.getId(), book);
		return true;
	}

	public boolean remove(Book b)
	{
		return remove(b.getId());
	}

	public boolean remove(int id)
	{
		if (!books.containsKey(id)) {
			return false;
		}
		books.remove(id);
		return true;
	}

	public Book find(int id)
	{
		return books.get(id);
	}
}

/*
* This class represents the UserManager which is responsible
* for managing the users, their membership etc.
*/
class UserManager {
	private HashMap<Integer, User> users;

	public UserManager()
	{
		users = new HashMap<Integer, User>();
	}
	public Boolean addUser(int id, String details, String name)
	{
		if (users.containsKey(id)) {
			return false;
		}
		User user = new User(id, details, name);
		users.put(id, user);
		return true;
	}

	public Boolean addUser(User user)
	{
		if (users.containsKey(user.getId())) {
			return false;
		}

		users.put(user.getId(), user);
		return true;
	}

	public boolean remove(User u)
	{
		return remove(u.getId());
	}

	public boolean remove(int id)
	{
		if (users.containsKey(id)) {
			return false;
		}
		users.remove(id);
		return true;
	}

	public User find(int id)
	{
		return users.get(id);
	}
}

/*
* This class represents the Display, which is responsible
* for displaying the book(pages and contents included). It also
* shows the current user.
*/
class Display {
	private Book activeBook;
	private User activeUser;
	private int pageNumber = 0;

	public void displayUser(User user)
	{
		activeUser = user;
		refreshUsername();
	}

	public void displayBook(Book book)
	{
		pageNumber = 0;
		activeBook = book;

		refreshTitle();
		refreshDetails();
		refreshPage();
	}

	public void turnPageForward()
	{
		pageNumber++;
		System.out.println("Turning forward to page no " +
				pageNumber + " of book having title " +
									activeBook.getTitle());
		refreshPage();
	}

	public void turnPageBackward()
	{
		pageNumber--;
		System.out.println("Turning backward to page no " +
					pageNumber + " of book having title " +
									activeBook.getTitle());
		refreshPage();
	}

	public void refreshUsername()
	{
		System.out.println("User name " + activeUser.getName() +
											" is refreshed");
	}

	public void refreshTitle()
	{
		System.out.println("Title of the book " +
						activeBook.getTitle() + " refreshed");
	}

	public void refreshDetails()
	{
		System.out.println("Details of the book " +
						activeBook.getTitle() + " refreshed");
	}

	public void refreshPage()
	{
		System.out.println("Page no " + pageNumber + " refreshed");
	}
}

/*
* This class represents the Book.
*/
class Book {
	private int bookId;
	private String details;
	private String title;

	public Book(int id, String details, String title)
	{
		bookId = id;
		this.details = details;
		this.title = title;
	}

	public int getId()
	{
		return bookId;
	}

	public void setId(int id)
	{
		bookId = id;
	}

	public String getDetails()
	{
		return details;
	}

	public void setDetails(String details)
	{
		this.details = details;
	}

	public String getTitle()
	{
		return title;
	}

	public void setTitle(String title)
	{
		this.title = title;
	}
}

/*
* This class represents the User.
*/
class User {
	private int userId;
	private String name;
	private String details;

	public void renewMembership()
	{
	}

	public User(int id, String details, String name)
	{
		this.userId = id;
		this.details = details;
		this.name = name;
	}

	public int getId()
	{
		return userId;
	}

	public void setId(int id)
	{
		userId = id;
	}

	public String getDetails()
	{
		return details;
	}

	public void setDetails(String details)
	{
		this.details = details;
	}

	public String getName()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}
}

public class AppTest {

	public static void main(String[] args)
	{

		OnlineReaderSystem onlineReaderSystem = new OnlineReaderSystem();

		Book book1 = new Book(1, "<알고리즘 문제 해결 전략>은 새로운 알고리즘 책입니다. 종이에 적힌 의사코드를 외우며 알고리즘을 배우는 대신, 해당 알고리즘을 적용해 푸는 프로그래밍 문제들을 직접 풀어보며 알고리즘 설계 기법과 자료 구조에 대해 배울 수 있도록 구성되어 있습니다. 풀이 과정은 독자가 글쓴이의 머릿속에서 일어난 문제 해결 과정을 최대한 이해할 수 있도록 설명되어 있습니다. 그래서 독자는 예전에는 피상적으로 이해하던 알고리즘과 자료 구조에 대해 이들이 어떻게 사용되는지, 왜 그렇게 되었는지에 대해 직관적으로 이해할 수 있게 됩니다.", "프로그래밍 대회에서 배우는 알고리즘 문제해결전략 1");
		Book book2 = new Book(2, "<알고리즘 문제 해결 전략>은 새로운 알고리즘 책입니다. 종이에 적힌 의사코드를 외우며 알고리즘을 배우는 대신, 해당 알고리즘을 적용해 푸는 프로그래밍 문제들을 직접 풀어보며 알고리즘 설계 기법과 자료 구조에 대해 배울 수 있도록 구성되어 있습니다. 풀이 과정은 독자가 글쓴이의 머릿속에서 일어난 문제 해결 과정을 최대한 이해할 수 있도록 설명되어 있습니다. 그래서 독자는 예전에는 피상적으로 이해하던 알고리즘과 자료 구조에 대해 이들이 어떻게 사용되는지, 왜 그렇게 되었는지에 대해 직관적으로 이해할 수 있게 됩니다.", "프로그래밍 대회에서 배우는 알고리즘 문제해결전략 2");

		onlineReaderSystem.getLibrary().addBook(book1);
		onlineReaderSystem.getLibrary().addBook(book2);

		User user1 = new User(1, " ", "철수");
		User user2 = new User(2, " ", "영희");

		onlineReaderSystem.getUserManager().addUser(user1);
		onlineReaderSystem.getUserManager().addUser(user2);

		onlineReaderSystem.setActiveBook(book1);
		onlineReaderSystem.setActiveUser(user1);

		onlineReaderSystem.getDisplay().turnPageForward();
		onlineReaderSystem.getDisplay().turnPageForward();
		onlineReaderSystem.getDisplay().turnPageBackward();
	}
}
```

</details>
