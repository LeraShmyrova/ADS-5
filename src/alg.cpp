// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int pr(char p) {
  if (p == '(') {
  return 0;
  } else if (p == ')') {
  return 1;
  } else if (p == '-') {
  return 2;
  } else if (p == '+') {
  return 2;
  } else if (p == '/') {
  return 3;
  } else if (p == '*') {
  return 3;
  } else if (p == ' ') {
  return 4;
  } else {
  return -2;
  }
}

int vichisl(char c, int op1, int op2) {
  if (c == '+') {
  return (op2 + op1);
  } else if (c == '-') {
  return (op2 - op1);
  } else if (c == '*') {
  return (op2 * op1);
  } else if ((c == '/') && (op1 != 0)) {
  return (op2 / op1);
  } else {
  return 0;
  }
}

std::string infx2pstfx(std::string inf) {
  std::string peremen;
  TStack <char, 100> TT;
  int j = 0;
  for (int j = 0; j < inf.size(); j++) {
  if (pr(inf[j]) == -2) {
  peremen.push_back(inf[j]);
  peremen.push_back(' ');
  } else {
  if (pr(inf[j]) == 0) {
  TT.push(inf[j]);
  } else if (TT.isEmpty()) {
  TT.push(inf[j]);
  } else if ((pr(inf[j]) > pr(TT.get()))) {
  TT.push(inf[j]);
  } else if (pr(inf[j]) == 1) {
  while (pr(TT.get()) != 0) {
  peremen.push_back(TT.get());
  peremen.push_back(' ');
  TT.pop();
  }
  TT.pop();
  } else {
  while (!TT.isEmpty() && pr(inf[j]) <= pr(TT.get())) {
  peremen.push_back(TT.get());
  peremen.push_back(' ');
  TT.pop();
  }
  TT.push(inf[j]);
  }
  }
  }
  while (!TT.isEmpty()) {
  peremen.push_back(TT.get());
  peremen.push_back(' ');
  TT.pop();
  }
  int i = 0;
  for (int i = 0; i < peremen.size(); i++) {
  if (peremen[peremen.size() - 1] == ' ')
  peremen.erase(peremen.size() - 1);
  }
  return peremen;
}

int eval(std::string pref) {
  int resultat = 0;
  TStack <int, 100> SS;
  int k = 0;
  for (int k = 0; k < pref.size(); k++) {
  if (pr(pref[k]) == -2) {
  SS.push(pref[k] - '0');
  } else if (pr(pref[k]) < 4) {
  int b = SS.get();
  SS.pop();
  int a = SS.get();
  SS.pop();
  SS.push(vichisl(pref[k], b, a));
  }
  }
  resultat = SS.get();
  return resultat;
}
