#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
  alphabet = u'ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ'
  alphabet_length = len(alphabet) 
  message = u'SÖUÖQDNHMTVSEETTIGKVIÄEÅSNRJBP'
  key = u'FSDNL'
  key_length = len(key)
  index = 0
  plain_text = []

  for symbol in message:
    num = alphabet.find(symbol)
    offset = alphabet.find(key[index])
    num = (num - offset) % alphabet_length
    index = (index + 1) % key_length
    plain_text.append(alphabet[num])

  print ''.join(plain_text)

if __name__ == '__main__':
  main()
