#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

int clean_up() { return 1;} 

void create()
{
              set("short", "��������"); 
              set ("long", 
          "�����������˺��������Ů����֥֥Ʒ��ͽӴ����ѵĵط�("CYN"sit"NOR")��\n"
      "�������������磬������Щ���Σ��Ϸ�����һ�����飺\n" 
          "    " BBLU CYN "�X���������������h���������������[\n" NOR
          "    " BBLU CYN "��" NOR BBLU HIC "��յ�α���������ֵܵ��ֺ���" NOR BBLU CYN "��\n" NOR
          "    " BBLU CYN "��" NOR BBLU HIC "һ��ƽ�ط粨�𣬴˼��ཻ�ż���" NOR BBLU CYN "��\n" NOR
          "    " BBLU CYN "�^���������������k���������������a\n" NOR


        ); 


        set("exits", ([
                   //"west"   : "/u/gigi/startroom",
                "north"  : "/u/redl/houdian",
                "south"  : __DIR__"dating",
        ]));

        set("objects", ([ 
                                "/u/redl/npc/queen" : 1, 
                                "/u/redl/obj/table" : 1,  
        ])); 

                set("no_fight", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_sleep_room", 1);

        setup();

        set("room_owner", "��������");
        set("room_name", "����");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "Ϫ��С·");
}


void init()
{
        add_action("do_sit", "sit");
        delete_temp("has_sit", this_player());
}

int do_sit(string arg)
{
        object me;
        string sex;
        int tea = 50000;

        me = this_player();
        
        if (!query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") return notify_fail("���ܽ���������ٺٺټ�Ц�˼�����\n");
        
        if ( me->is_busy() ) {
                        tell_object(me, "�㻹��æ����ͷ�ϵ�������˵�ɡ�\n");
                        return 1;
                }
        me->start_busy(2);
        
        sex = query("gender", me);
        
        if( query_temp("has_sit", me) )
        {
                switch(random(7)) {
                        case 0:
                        case 1:
                        message_vision(CYN "$NĬĬ��������˼��ǰ��ҡ��ҡ���ӡ�\n" NOR, me);
                        break;
                case 2:
                        case 3:
                        message_vision(CYN "$N����������ס�죬С���ؿ����˼�����\n" NOR, me);
                        break;
                case 4:
                        case 5:
                        message_vision(CYN + ((sex=="����")? "$N��֪��������ʲô�£��ѿ����촽�Ǻ�Ц��Ц��\n" : "$N��֪��������ʲô�£������۾�Ц������������\n") + NOR, me);
                        break;
                default:
                        message_vision(CYN "$N�������ϵ���֥���Ӳ裬�������͵���������һ�ڡ�\n" NOR, me);
                                        if ( !query_temp("has_drinkredltea", me) ) {
                                                call_other(GIFT_D, "bonus", me, ([ "exp":tea, "pot":tea/4, "mar":tea/10, "prompt":"���ں�����֥���Ӳ��"]));
                                message_vision(HIG "$N����δ�����������������˼�����͡�\n" NOR, me);
                                        }
                                        set_temp("has_drinkredltea", 1, me);//��quit��ڶ����ٻ�����������ǲ�������Ч������
                        break;
            }
            return 1;
        }

                                message_vision(CYN "$NѰ��һ�ѿ����ӣ���������������\n" NOR, me);
                                set_temp("has_sit", 1, me);
        return 1;
}

int valid_leave(object me, string dir)
{
                string sex = query("gender", me);
                
        if( query_temp("has_sit", me) )
        {
                        message_vision(CYN + ((sex=="����")? "$N�������������뿪����վ��������\n" : "$N���˶�ȹ�ӣ��뿪����վ��������\n") + NOR, me);
                        delete_temp("has_sit", me);
        }

        return ::valid_leave(me, dir);
}


