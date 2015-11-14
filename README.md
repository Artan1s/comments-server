# comments-server

Система комментирования. Предполагается, что уже есть что комментировать (во внешней системе).
Пользователь пожет добавить свой коментарий, отредактировать его или проголосовать +1 или -1 за чей-то еще коментарий.

## Data Schema


There are following data types:

* *NEW_COMENT*, *COMENT_EDITION*:
    
```
    
{
    "Text": "This comment is very straightforward."
}
    
```

* *COMMENT*:
    
```
    
{
    "CreationDate": "YYYY-MM-DD HH:MM:SS",
    "LastEditedDate": "YYYY-MM-DD HH:MM:SS",
    "Text": "This comment is very straightforward.",
    "Rating": -5
}
    
```


## API

### Create Comment Record
* **Request**
	* **URL:** `/comments`
	* **Method:** `POST`
	* **Body:** *NEW_COMENT*
* **Response**
	* **Code:** `201 HTTP_CREATED`
	* **Body:** Id of created record

### Get Comment by Id
* **REQUEST**
    * **URL:** `/comments/{id}`
    * **Method:** `GET`
* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:** `200 HTTP_OK`, `404 HTTP_NOT_FOUND`
    * **Body:** *COMMENT*

### Edit Commentby Id
* **Request**
	* **URL:** `/comments`
	* **Method:** `PATCH`
	* **Body:** *COMENT_EDITION*
* **Response**
	* **Code:** `200 HTTP_OK`, `404 HTTP_NOT_FOUND`

### Delete Comment by Id
* **REQUEST**
    * **URL:** `/comments/{id}`
    * **Method:** `DELETE`
* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:** `200 HTTP_OK`, `404 HTTP_NOT_FOUND`
    * **Body:** *COMMENT*

### Upvote Comment by Id
* **Request**
	* **URL:** `/comments/{id}/upvotes`
	* **Method:** `POST`
* **Response**
	* **Code:** `200 HTTP_OK`, `404 HTTP_NOT_FOUND`

### Downvote Comment by Id
* **Request**
	* **URL:** `/comments/{id}/downvotes`
	* **Method:** `POST`
* **Response**
	* **Code:** `200 HTTP_OK`, `404 HTTP_NOT_FOUND`
