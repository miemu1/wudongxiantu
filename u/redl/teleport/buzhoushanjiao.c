// This program is a part of NITAN MudLIB  
// redl 2015/10
#include <ansi.h>  
#include <room.h>  
inherit __DIR__"normal.c";  

void create()
{
        set("short","����ɽ��");
        set("long", @LONG
�����ǲ���ɽ���ഫ����ɽ���˽�Ψһ�ܹ���������·����
ֻ��ϧ����ɽ���꺮�䣬����Ʈѩ���Ƿ�����������ͽ�������
�����з���Ϊ������һ���ֻ����ɽ����ȴδ�����䷵�硣
LONG );
        set("outdoors", "yangzhou");
        set("exits",([
            "out"       :       "/u/redl/teleport/teleport",
            "up"        :       __DIR__"bzs/bzs_1",
        ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_magic", 1); 
        set("no_user_kill", 1); 
        set("no_sleep_room", 1);  

           set("objects", ([ 
                     "/clone/npc/walker"  : 2, 
           ])); 

        setup();
}

int existroom(string s)
{
        if (file_size(s) > 0) return 1;
        return 0;
}

int needcreate(string s)
{
        object room = get_object(s);
        if (sizeof(query("exits", room)) >= 6) return 1;
        return 0;
}

int createroom()
{
        string lvs, ds, dstfile, filename; 
        int lv = 1;

    if (!sizeof(get_dir(__DIR__"bzs"))) mkdir(__DIR__"bzs");
    
        while (lv) {
                filename = __DIR__"bzs/bzs_" + (string)lv + ".c";
                if (existroom(filename)) {
                        if (needcreate(filename)) {
                                lv++;
                                continue;
                        }
                        break;
                }
                //��������
                if (file_size(__DIR__"bzs.c") < 1) break;//ģ���ļ�ȱ��
                dstfile = read_file(__DIR__"bzs.c");
                lvs = (string)(lv + 1);
                if (lv == 1) 
                        ds = "set(\"exits\",([\"down\":\"/u/redl/teleport/buzhoushanjiao\",\"up\":__DIR__\"bzs_"+lvs+"\"]));setup()";
                else 
                        ds = "set(\"exits\",([\"down\":__DIR__\"bzs_"+(string)(lv - 1)+"\",\"up\":__DIR__\"bzs_"+lvs+"\"]));setup()";
                dstfile = replace_string(dstfile, "setup()", ds);
                dstfile = replace_string(dstfile, "����ɽname", "����ɽ��" + (string)(500 + (lv-1) * 20 + random(10)) + "��");
                write_file(filename, dstfile, 1);
                break;
        }
}

int valid_leave(object me, string dir)
{
                if (dir=="out") {
                         if (!playerp(me)) return 0;
                         return ::valid_leave(me, dir);
                }
                
        if (playerp(me) && !interactive(me)) return 0;
        
        if (playerp(me)) {
                if (query("level", me) < 10) return notify_fail(NOR "һ��������ֹ�㣺�ȼ�̫�Ͳ����ɽ��\n" NOR);
                if( query("online_time", me) < 21600)  return notify_fail(NOR "һ��������ֹ�㣺�������䲻�������ɽ��\n" NOR);
        }
        
        return ::valid_leave(me, dir);
}

void init()  
{
        object me = this_player(); 
        if (!playerp(me)) return;
        //me->start_busy(2);
        if (query("createroom_time") < time()) {
                        set("createroom_time", time() + 150);//��������
                        createroom();
        }
}  


