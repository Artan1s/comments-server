# comments-server

Система комментирования. Предполагается, что уже есть что комментировать (во внешней системе).
Пользователь пожет добавить свой коментарий, отредактировать его или проголосовать +1 или -1 за чей-то еще коментарий.

## CAP

Сервис будет реализовывать модель AP.

### C
Согласованность данных не является важным параметром данной системы, так как, исходя из предназначения системы, не предполагается, что на основе количества голосов и текстов комментариев будут приниматься какие-либо важные решения и предприниматься действия. Все эти данные по своей природе носят приблизительный характер.
Поэтому обеспечение согласованности излишне.

### A
Так как обеспечение согласованности данных не требуется, есть возможность обеспечить доступность. Что в свою очередь является важным параметром для системы.

### P
Предполагается, что система будет разворачиваться на нескольких узлах, соответственно появляется риск расщепления системы. А так как корректная работа системы, очевидно, является желаемой характеристикой, и учитывая, что нет нужды поддерживать согласованность, то к системе предъявляется требование по обеспечению устойчивости к расщеплению.

Для реализации системы будет использоваться база данных CouchDB — она реализует подход AP.

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
