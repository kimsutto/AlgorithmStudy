def solution(phone_book):
    phone_book.sort()
    for n1, n2 in zip(phone_book,phone_book[1:]):
        return not n2.startswith(n1)
