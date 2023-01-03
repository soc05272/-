#include "std.h"
#include <stdlib.h>

struct student * s_input1();
int s_inputall();
extern int count;
extern struct student *head, *tail;

int s_inputall()
{
	        int i, hakbun;
		        struct student *ptr,*pptr;

			        printf("------------------------------\n");
				   for(i=0;i<MAX_STUDENT;i++) {
					           printf("input id number :");
						           scanf("%d",&hakbun);
							           if(hakbun == -1)
									                   return(-1);
								           ptr = (struct student *)malloc(sizeof(struct student));
									           if(head == NULL)
											                   head = ptr;
										           else
												                   tail->next = ptr;
											           ptr->hakbun = hakbun;

												           printf("input your name :");
													           scanf("%s",ptr->name);

														           printf("input sex :");
															           scanf("%s",ptr->sex);
																           printf("input korean :");
																	           scanf("%d",&(ptr->kor));
																		           if(ptr->kor < 0 || ptr->kor > 100){
																				                   printf("국어점수 오류 : %d\n", ptr->kor);
																						                   return(-2);
																								           }
																			           printf("input math :");
																				           scanf("%d",&(ptr->math));
																					           if(ptr->math < 0 || ptr->math > 100){
																							                   printf("수학점수 오류 : %d\n", ptr->math);
																									                   return(-2);
																											           }
																						           ptr->next = NULL;
																							           tail = ptr;
																								           count++;
																									       } 
				           return 0;
}

struct student * s_input1()
{
	        int hakbun;
		        struct student *ptr;

			        printf("input id number :");
				        scanf("%d",&hakbun);
					        if(hakbun == -1)
							                return NULL;

						        ptr = (struct student *)malloc(sizeof(struct student));
							        ptr->hakbun = hakbun;

								        printf("input your name :");
									        scanf("%s",ptr->name);
										printf("input sex :");
										        scanf("%s",ptr->sex);
											        printf("input korean :");
												        scanf("%d",&(ptr->kor));
													        if(ptr->kor < 0 || ptr->kor > 100){
															                printf("국어점수 오류 : %d\n", ptr->kor);
																	                return NULL;
																			        }
														        printf("input math :");
															        scanf("%d",&(ptr->math));
																        if(ptr->math < 0 || ptr->math > 100){
																		                printf("수학점수 오류 : %d\n", ptr->math);
																				
																				                return NULL;
																						        }
																	        return ptr;
}
