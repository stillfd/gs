#pragma once

#define DEF_SNAKE_LONG 20
char g_strGameBack[20][48] = {  "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö                                          ¡ö\n",
								"¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö\n" };

//diresction
enum {to_east = 2, to_west = -2, to_north = -1, to_south = 1};
// array of snake
int g_arrSnake[DEF_SNAKE_LONG][3] = { 0 };

//DIR OF SNAKE
int g_nSnakeDir = to_west;