// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;


void create()
{
        set("short", "������");
        set("long", @LONG
�ھ޴�������£�����һ���������֮����΢�粦��������������Ҷ��
�������Ϣ�����Ŀ��������ƺ�һ�г������վ���������ɢ��
LONG );

              set("objects", ([ 
                      "/u/gigi/obj/food/putiguo" : 1, 
              ])); 
        set("exits", ([ /* sizeof() == 1 */
                "down" : "/u/gigi/swing",
        ]));

        set("no_fight", "1");
        set("no_rideto", 1);
        set("no_flyto", 1);

        set("no_clean_up", 0);
        setup();
                      remove_call_out("do_star"); 
                     call_out("do_star", 5);
}

              int do_star() 
      { 
                      switch(random(11)) { 
                              case 0: 
                              case 1: 
                              case 2: 
                              case 3: 
                              tell_room(this_object(), HIK "������"NOR HIG "','�q �Шr�𡡨u����u�u�����u�u����.���Шr','�q �Шr���u�����Ϩu�u���u�u����.���Шr" NOR HIK "�������\n"NOR); 
                              break; 
                              case 4: 
                              case 5: 
                              case 6: 
                              tell_room(this_object(), HIK "������"NOR HIR "',',' ','�u���u����u��u�u�������u�u',��',' ','�u���u����u����u�u�ǡ��u�u" NOR HIK "�������\n"NOR); 
                              break; 
                              case 7: 
                              case 8: 
                              tell_room(this_object(), HIK "������"NOR HIC "�q' �Шr,��u����u�u�u�� �u�Шr�����u ���q' �Шr,��u����u�u�u譡�� �u�Шr�u  ��" NOR HIK "�������\n"NOR); 
                              break; 
                              case 9: 
                              tell_room(this_object(), HIK "������"NOR HIY "'��u���u' �Шr�����u���š��u���š��� ',''��u���u' �Шr�����u��á��񡡨u��� ','" NOR HIK "�������\n"NOR); 
                              break; 
                      case 10: 
                              tell_room(this_object(), HIK "������"NOR HIB "��.���Шr�u�u',','���u�u' �����r��,��u��.���Шr�u�u',','���u�u' �۾���С�r,�� �u" NOR HIK "�������\n"NOR); 
                              break; 
                  } 
              call_out("do_star", 30 + random(20));               
              return 1; 
      } 
