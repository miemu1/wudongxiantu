// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h>

inherit ROOM;

#define FILEPATH "/u/redl/teleport/"

int clean_up() { return 1;}

mapping *sign = ({
        ([      "file"          :       FILEPATH "tower",       
                "loop"          :       FILEPATH,                               //����֧��ʱ����鷿�䷶Χ
                "val"           :       50000                                   
        ]),
        ([      "file"          :       FILEPATH "qiulao",      
                "loop"          :       FILEPATH,
                "val"           :       10000                                   
        ]),
        ([      "file"          :       FILEPATH "tiangong",    
                "loop"          :       FILEPATH,
                "val"           :       30000                                   
        ]),
        ([      "file"          :       FILEPATH "shike",       
                "loop"          :       FILEPATH,
                "val"           :       650000                                   
        ]),
        ([      "file"          :       FILEPATH "baodu",       
                "val"           :       90000000                                        
        ]),
              ([      "file"          :       FILEPATH "lankeshan",        
                      "val"           :       1000000                                                     ]), 
        ([      "file"          :       FILEPATH "huaguo",       
                "loop"          :       FILEPATH,
                "val"           :       10000000                                        
        ]),
       ([      "file"          :       FILEPATH "18niuren",       
                "loop"          :       FILEPATH,
                "val"           :       10000000                                        
        ]),
        ([      "file"          :       FILEPATH "ailao",       
                "val"           :       1000000000                                        
        ]),
        ([      "file"          :       FILEPATH "buzhoushanjiao",       
                "val"           :       10000                                        
        ]),
        ([      "file"          :       "/d/pk/entry",  
                "val"           :       500000                                  
        ]),
});


string look_kong(object me)
{
        string msg;
        int j = 0;
        int i = -1;

        msg = CYN
"���Ա��м����֣�\n"
"  ������Ի�����Ʒ����󡻣������Դ��㴩�����صĵط���\n"
"  ����Ҫ���Ѳ�����ά������������ָ�<put ���� ����>\n" NOR;  
        while(i++<sizeof(sign)-1){
                if (sign[i]["short"]) {
                        msg += sprintf(" %-28s",  sign[i]["exit"] + ":" + sign[i]["short"] + "("+ chinese_number(sign[i]["val"]/10000) + "��" + (sign[i]["loop"]? "ά��":"����") +")");
                        j ++;
                        if (j>1) {
                                msg += "\n";
                                j = 0;
                        }
                }
        }
        if (j!=0) msg += "\n";
        
        return msg;
}

void create_exit()
{
        object ob;
        int i = -1;
        int k = 1;
        
        while(i++<sizeof(sign)-1){
                if (sign[i]["file"]) {
                        ob = load_object(sign[i]["file"]);
                        if (objectp(ob)){
                                sign[i] += (["short" : query("short", ob)]);
                                sign[i] += (["exit" : sprintf("%d", k)]);
                                k++;
                                set("exits/" + sign[i]["exit"], sign[i]["file"]);
                        }
                }
        }
}

int do_put(string arg)
{
        object me;
        object ob;
        object nob;
        object *inv;
        string my_id, units;
        int amount;
        int value;
        int max_count;
        int i;
        mixed ns;

        if( !arg )
        {
                        write(NOR "��Ҫ��ʲôͶ��ȥ��\n" NOR);
                        return 1;
        }

        me = this_player();

                if ((time() - query_temp("teleportroom/put_time", me)) < 6) 
        {
                        write(NOR "����������������ʲô����һ�����Ͷ�ɡ�\n" NOR);
                        return 1;
        }

        if(!interactive(me) || !playerp(me) || me->is_busy()) {
                        write(NOR "����æ���ء�\n" NOR);
                        return 1;
        }
                
        if( sscanf(arg, "%d %s", amount, arg) != 2 )
                // not indicate the amount of the goods
                amount = 1;

        if( amount < 1 )
        {
                write(NOR "�㵽����Ͷ�����أ�\n" NOR);
                return 1;
        }
        
        ob = present(arg, me);
        if( !ob )
        {
                inv = all_inventory(me);
                for( i = 0; i < sizeof(inv); i++ )
                {
                        if( filter_color(inv[i]->name(1)) == arg )
                        {
                                ob = inv[i];
                                break;
                        }
                }
        }

        if ( !objectp(ob) )
        {
                write("������û�����ֶ�������\n");
                return 1;
        }

        if (!query("money_id", ob))
        {
                write(NOR "������ֻ��ͶǮŶ��\n" NOR);
                return 1;
        }
        
      max_count = ob->query_amount();
        if( !max_count )
        {
                // not combined object
                if( amount > 1 )
                {
                        write(NOR + "��" + ob->name() + NOR + "��ʲô������\n" + NOR);
                        return 1;
                }
                max_count = 1;
        } else
        {
                // is combined object
                if( amount > max_count )
                {
                        write(NOR + "������û����ô��" + ob->name() + NOR + "��\n" + NOR);
                        return 1;
                }
        }
        
                value = query("base_value", ob) * amount;
                
        if( value < 1000000 )
        {
                write(NOR "����һ�����ƽ��ò���������Ҳ̫�����˵��...\n" NOR);
                return 1;
        }
                
                set_temp("teleportroom/put_value", value, me);
                set_temp("teleportroom/put_time", time(), me);

        units = query("base_unit", ob);
        if (!units) units = query("unit", ob);
        if (!units) units = "��";
                
        message_vision(append_color(CYN + "$N�ͳ�" + chinese_number(amount) + units + ob->name() + CYN + "�߹�ȥ��������ӭ��ǰ�ù���ת��������Ͷ��Щ����ʯ��\n" + NOR, CYN), me);

                if( max_count == amount ) {
                        destruct(ob);
                }
                else
                {
                        ob->add_amount(-amount);
                }
                
        return 1;
}


int do_look(string arg)
{
        object me = this_player();
        //if ( arg && sscanf(arg, "%*d") ) {
        if ( arg && arg!="south" && arg!="southeast" && query("exits/" + arg) && wiz_level(me) < 5 ) {
                        tell_object(me, NOR "������Ŀ������ȥ��ȴֻ���������������\n" NOR);
                        return -1;
        }
        return 0;
}

int init() 
{ 
        object me = this_player();
        if (!interactive(me) || !playerp(me)) return 1;
        add_action("do_look", "look");
        add_action("do_put","put"); 
        if (wiz_level(me) > 5) {
                add_action("do_stop", "stop");
        }
        return 1;
} 

int do_tell_val(object me)
{
        tell_object(me, sprintf(HIG "���Ʒ������㴢�����������(%d)�㡣\n\n" NOR, query_temp("teleportroom/put_value", me)/10000)); 
        return 1;
}

int do_tell_back(object me)
{
        //tell_object(me, sprintf(HIG "\n���һ����������������ס����..\n\n" NOR)); 
        message_vision(append_color(NOR + YEL + "\n���һ����������������ס��$N..\n\n" + NOR, YEL), me);
        me->move(this_object());
        //tell_object(me, sprintf(HIG "������ת�У���ͷ��Ŀѣ�ر������˷���\n\n" NOR)); 
        message_vision(append_color(NOR + YEL + "������ת�У�$Nͷ��Ŀѣ�ر������˷���\n\n" + NOR, YEL), me);
        return 1;
}

int is_area(mapping my)
{
        object me = my["ob"];
        
        if ( !objectp(me) || 
                !playerp(me) ||
                !interactive(me) ||
                !environment(me) ||
                !objectp(environment(me)) || 
                base_name(environment(me))==base_name(this_object()) ) return 0;
        if ( !sscanf(base_name(environment(me)), sprintf("%s", my["path"]) + "%*s") ) return 0;
        
        if (query_temp("teleportroom/put_value", me) < my["cost"] && time()-my["time"] > 59) {
                do_tell_back(me);
                return -1;
        }
        
        if (time()-my["time"] > 59) {
                addn_temp("teleportroom/put_value", -my["cost"], me);
                do_tell_val(me);
                return 1;
        }
        
        return 2;
}

int check_teleroom()
{
        mapping usrs;
        string *ks;
        int i, count;
        
        remove_call_out("check_teleroom");
        usrs = query("tele_users");
        if (sizeof(usrs)) {
                ks = keys(usrs);
                for(count=sizeof(ks); count > 0; count--)
                {
                        //tell_object(find_player("redl"), sprintf("%s\n", ks[count-1])); 
                        switch ( is_area(query("tele_users/" + ks[count-1])) ) {
                                case -1 :
                                case 0 :
                                        delete("tele_users/" + ks[count-1]);
                                        break;
                                case 1 : 
                                        set("tele_users/" + ks[count-1] + "/time", time());
                                        break;
                                default :
                                        break;
                        }
                }
        }
        
        call_out("check_teleroom", 10);
}

int do_stop()//���峡���ٸı�
{
        mapping usrs;
        string *ks;
        int i, count;
        object ob;
        object me = this_player();
        
        if (query("do_stop")) {
                delete("do_stop");
                check_teleroom();
                tell_object(me,YEL + "ά����ϣ�����ʹ�ã�\n" + NOR); 
        } else {
                set("do_stop", 1);

                remove_call_out("check_teleroom");
                usrs = query("tele_users");
                if (sizeof(usrs)) {
                        ks = keys(usrs);
                        for(count=sizeof(ks); count > 0; count--)
                        {
                                //tell_object(find_player("redl"), sprintf("%s\n", ks[count-1])); 
                                switch ( is_area(query("tele_users/" + ks[count-1])) ) {
                                        case -1 :
                                        case 0 :
                                                delete("tele_users/" + ks[count-1]);
                                                break;
                                        case 1 : 
                                        default :
                                                ob = query("tele_users/" + ks[count-1])["ob"];
                                                if (ob && playerp(ob)) {
                                                        do_tell_back(ob);
                                                }
                                                break;
                                }
                        }
                }
                message_vision(append_color(NOR + CYN + "$N��������������ʼά�ޣ��ݻ�ʹ�á�\n" + NOR, CYN), me);
        }
        
        return 1;
}

int valid_leave(object me, string dir)
{
        object room, *inv;
        int countp;
        int value, i = sizeof(sign);

        if (!interactive(me) || !playerp(me)) return 0;
        
        if (query("do_stop") && wiz_level(me) < 5 && dir != "southeast" && dir != "south" && dir != "southwest") 
        {
                tell_object(me, NOR + "��������ά�ޣ���ֹʹ�ã�\n" + NOR); 
                return -1;
        }

        if( me->query_condition("killer") ) {
                tell_object(me, NOR"�����ڱ�ͨ�����޷����������\n"NOR);
                return -1;
        }

                        inv = deep_inventory(me);
                        if( sizeof(inv) > 0  && wiz_level(me) < 5 && dir != "southeast" && dir != "south" && dir != "southwest") {
                                        foreach( object ob2 in inv ) {
                                        if( ob2->is_character() && base_name(ob2)!="/clone/user/baby" ) {
                                        message_vision(append_color(NOR + CYN + "���������˳�����Χס$N��ָ��ָ�����ϵ�$n��\n" + NOR, CYN), me, ob2);
                                return -1;
                                        }
                                        }
                                  }
        
                if (query("exits/" + dir)) room = get_object(query("exits/" + dir));
                if (room && objectp(room) && query("max_carry_user", room)) {//��������
                        inv = all_inventory(room);
                        if( sizeof(inv) > 0 ) {
                foreach( object ob3 in inv ) {
                        if ( playerp(ob3) && wiz_level(ob3) < 5 ) countp ++;
                }
                }

                if(query("max_carry_user", room) < countp + 1 && wiz_level(me) < 5) {
                                tell_object(me, "�㷢�ֶ������̫���ˣ����ֿռ䲻�ȶ���״̬���ŵò���̤��������\n");  
                                me->start_busy(2);
                                return -1;      
                }
                }
        
        while(i--){
                if (sign[i]["exit"] && sign[i]["exit"]==dir) {
                        value = sign[i]["val"];
                        break;
                }
        }        
        
        if (value && wiz_level(me) < 5){
        //if (wiz_level(me) < 5){       
                if (query_temp("teleportroom/put_value", me) < value) {
                        message_vision(append_color(NOR + CYN + "���������˳�����Χס$N��ָ��ָʯ̨�ϵĿ�" + HIK + "(���Ǯû�ɹ���look kong������۸�)" + NOR + CYN + "��\n" + NOR, CYN), me);
                me->start_busy(3);
                        return -1;
                }
                else {
                        addn_temp("teleportroom/put_value", -value, me);
                        if (sign[i]["loop"]) {
                                set("tele_users/" + query("id", me), ([ "ob"    :       me, 
                                                                                                             "cost"  :       value,
                                                                                                             "path"  :       sign[i]["loop"],
                                                                                                             "time"  :       time()
                                                                                                      ]));
                        }
                        do_tell_val(me);
                        message_vision(append_color(NOR + CYN + "$N" + (random(2) ? "����" : "����") + "����" + (random(2) ? "ʯ̨" : "����") + "����������" + (random(2) ? "һ��������" : "һ��������") + "��$N����Ӱ" + (random(2) ? "��ʧ" : "��ȥ") + "��\n" + NOR, CYN), me);
                        return 1;
                }
        }
        
        return ::valid_leave(me, dir);
}

void create()
{
        set("short", HIG "���Ƿ���" NOR);
        set ("long", NOR
"������һ��������󷨿ռ䣬�˸��޴��ʯ�����������ʯ����\n"
"�����һ�ţ���Χ��˸����ɫ��ɫ��ɫ�ĵ��ߡ�������Ե��ʯ̨����\n"
"���и�С��("CYN"kong"NOR")������վ�ż������ܻ����ˡ�\n"NOR
        );
                set("exits",([ /* sizeof() == 1 */
                        "south" : "/d/city/kedian4",
                        "southeast" : "/d/city/qiyuan/xxzl1",
                        "southwest" : "/u/redl/school/gate",
                ]));

        set("objects", ([ 
//                                                "/u/redl/teleport/npc/tester" : 1,
        ])); 
        
        set("item_desc", ([
                "��": (: look_kong :),
                "kong": (: look_kong :),
        ]) );
        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        setup();
        create_exit();
        check_teleroom();
}



