#include "Profile.h"

void Profile::init(User owner)
{
	_user = owner;
	_page.init();
	_List_Of_Friends.init();
}

void Profile::clear()
{
	_page.setStatus("");
	_List_Of_Friends.clear();
	_page.cleanPage();
}

User Profile::getOwner() const
{
	return _user;
}

void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_List_Of_Friends.add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string Page = "Status: " + _page.getStatus() + "\n";
	Page = Page + "*******************\n" + "*******************\n";
	Page = Page + _page.getPosts();
	return Page;
}

std::string Profile::getFriends() const
{
	UserNode* curr = _List_Of_Friends.get_first();
	std::string Friends = "";
	while (curr)
	{
		Friends = Friends + curr->get_data().getUserName() + ",";
		curr = curr->get_next();
	}
	Friends.pop_back();
	return Friends;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	int user_Name_Size = _user.getUserName().length();
	std::string friends_Same_Lenght = "";

	UserNode* curr = _List_Of_Friends.get_first();
	while (curr)
	{
		if (curr->get_data().getUserName().length() == user_Name_Size)
		{
			friends_Same_Lenght = friends_Same_Lenght + curr->get_data().getUserName() + ",";
		}
		curr = curr->get_next();
	}
	if (!friends_Same_Lenght.empty())
		friends_Same_Lenght.pop_back();

	return friends_Same_Lenght;
}