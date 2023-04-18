#pragma once

template<typename T> struct TypeID;
template<size_t id> struct IDType { using T = void; };//set the Type to void for all undefined structs

//NOTE: put this definition of the type and id ONLY INTO .CPP FILES!!! (-> doesnt work if the GetId method is defined multiple times)
#define DEF_TYPE_ID(type, id) template<> struct TypeID<type> { static constexpr size_t ID = id; };\
							  template<> struct IDType<id>	 { using T = type; };
#define GET_ID_METHOD(type) size_t type::GetId() const { return GET_ID(type); }//defines the "GetId"-method
#define GET_ID(type) TypeID<type>::ID
#define GET_TYPE(id) IDType<id>::T


constexpr size_t ID_COUNT = 3;

void* CreateOjFromId(size_t id);