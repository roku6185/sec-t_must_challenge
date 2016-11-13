#!/usr/bin/env python
# -*- coding: utf-8 -*-
import fractions

def main():
  alphabet = u'ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ'
  alphabet_length = len(alphabet) 
  #message = u'TESTARMEDDELANDEMEDÅOCHÄOCHÖ'
  message = u'JMPJHVWMSSMÖHQSMWMSZKYXTKYXN'
  print 'Alphabet length: %d' % alphabet_length

  #encrypted_message = encrypt(message, alphabet, 23, 7)
  #print encrypted_message

  for a_inv in range(1, alphabet_length):
    for b in range(1, alphabet_length):
      if fractions.gcd(a_inv, alphabet_length) == 1:
        decrypt(message, alphabet, a_inv, b)

def encrypt(message, alphabet, a, b):
  alphabet_length = len(alphabet)
  print 'a=%d,b=%d,mod=%d' % (a, b, alphabet_length)
  cipher_text = []

  for symbol in message:
    index = alphabet.find(symbol)
    new_index = (a * index + b) % alphabet_length
    new_symbol = alphabet[new_index]
    cipher_text.append(new_symbol)

  return u''.join(cipher_text).encode('utf-8')

def decrypt(message, alphabet, a_inv, b):
  alphabet_length = len(alphabet)
  plain_text = []

  for symbol in message:
    index = alphabet.find(symbol)
    new_index = (a_inv * (index - b)) % alphabet_length
    new_symbol = alphabet[new_index]
    plain_text.append(new_symbol)

  result = u''.join(plain_text).encode('utf-8')
  print 'a^-1=%d,b=%d,mod=%d => %s' % (a_inv, b, alphabet_length, result)

if __name__ == '__main__':
  main()
