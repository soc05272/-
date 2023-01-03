#include "std.h"
#include <stdlib.h>
 
  int count = 0;
    extern int s_inputall(),s_insert(),s_search(int), s_delete(int);
      extern void s_process(),s_output(),s_class_output();
        extern struct student * s_input1();
	  struct student *head,*tail;
	   
	    int main()
	  {
		            int result, menu, hakbun;
			     
			          head = tail = NULL;
				        while(1) {
						          printf("+============================================================+\n");
							            printf("| MENU:(1)끝에연속추가,(2)추가,(3)탐색,(4)삭제,(5)출력,(6)종료   |\n");
								              printf("+============================================================+\n");
									                printf("원하는 메뉴를 선택하시오 : ");
											          scanf("%d",&menu);
												            if(menu <= 0 || menu > 6 ) {
														                      printf("없는 메뉴입니다.\n");
																                        continue;
																			          }
													              if(menu == 1) { 
															                        result = s_inputall();
															        
															                         if(result == -1) {
																			                           if(count == 0) {
																							                                     printf("학생 수는 0명 입니다\n");
																											                                       continue;
																															                                 }
																						                             else {
																										                                       s_process();
																														                                         s_output();
																																			                                   s_class_output();
																																							                                     continue;
																																											                               }
																									                       } 
																		                   else if(result == -2) { 
																					                             printf("점수 오류\n");
																								                               continue;
																											                         }
																				                     else continue;
																						               }
														                else if(menu == 2) { 
																	                  if(head == NULL) {
																				                            printf("첫번째 학생입니다 : \n");
																							                              head = s_input1();
																										                                tail = head;
																														                  }
																			                    else {
																						                              result = s_insert();
																									                                if(result == -1) {
																														                                  printf("추가 오류\n");
																																		                                    continue;
																																						                              }
																													                  }
																					                      count++;
																							                        s_process();
																										                  s_output();
																												                    s_class_output();
																														                      continue;
																																                }
																          else if(menu == 3) { 
																		                    if(count == 0) {
																					                              printf("학생은 0명 입니다\n");
																								                                continue;
																												                  }
																				                     printf("탐색 학번 : ");
																						                       scanf("%d",&hakbun);
																								                        result = s_search(hakbun);
																											                  if(result == -1)
																														                            printf("해당 학번이 존재하지 않음 !!!\n");
																													                    continue;
																															              } // 탐색
																	            else if(menu == 4) { // 삭제
																			                      if(count == 0) {
																						                                printf("학생은 0명 입니다\n");
																										                          continue;
																													                    }
																					                        printf("삭제 학번 : ");
																								                  scanf("%d",&hakbun);
																										                    result = s_delete(hakbun);
																												                     if(result == -1){
																															                              printf("삭제 오류 : \n");
																																		                               continue;
																																					                        }
																														                      count--;
																																                       if(count != 0) {
																																			                                s_process();
																																							                         s_output();
																																										                          s_class_output();
																																													                   }
																																		                        continue;
																																					         } // 삭제
																		             else if(menu == 5) { 
																				                      if(count == 0) {
																							                               printf("학생은 0명 입니다\n");
																										                                continue;
																														                 }
																						                       s_output();
																								                        s_class_output();
																											                 continue;
																													          } 
																			              else if(menu == 6) break;
																				          } 
					    return 0;
					     }

