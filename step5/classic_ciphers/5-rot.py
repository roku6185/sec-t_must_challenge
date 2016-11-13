#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
  alphabet = u'ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ'
  alphabet_length = len(alphabet) 
  message = u'SÖUÖQDNHMTVSEETTIGKVIÄEÅSNRJBP'
  num = 0

  for x in alphabet:
    plain_text = []
    num = num + 1

    for symbol in message:
      index = alphabet.find(symbol)
      new_index = (index + num) % alphabet_length
      new_symbol = alphabet[new_index]
      plain_text.append(new_symbol)

    print ''.join(plain_text)

if __name__ == '__main__':
  main()
