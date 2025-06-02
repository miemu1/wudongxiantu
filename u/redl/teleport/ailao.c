// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

int clean_up() { return 1;}

void create()
{
        set("short", "����ɽ");
        set("long", 
"�����ǰ���ɽ��´���嶥վ�ż�λ�޵��ߣ�ɽ�����ǹ������ʵ�\n"
"Ԫ������ֻ���������һ�ɹɴִ����˿��������ס��Ԫ����һֻ��\n"
"��Ľ𴬣�����������������\n"        
);
                set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                        "wiz"   : __DIR__"yuanjiang/jiaban",
                ]));
        set("objects", ([ 
                        __DIR__"yuanjiang/npc/zheng" : 1,
        ])); 
        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        //set("max_carry_user" ,3);
        //set("max_carry_exit" ,"out");
        setup();
        "/clone/board/jinchuan_b"->foo(); 
}

void countheads()
{
        object room, *npcs, *usrs, *allusrs = ({});
        int lv, count = 0;
    set("level_max", 80, this_object());
    set("level_min", 20, this_object());
        for (int i=0;i<50;i++) {
                room = get_object(__DIR__"yuanjiang/chuan" + (string)i);
                if (!objectp(room)) continue;
                    usrs = filter_array(all_inventory(room), (: playerp($1) :));
            if (sizeof(usrs)) 
                allusrs = allusrs + usrs;
            npcs = filter_array(all_inventory(room), (: query("guarder_level",$1)>0 :));
            if (sizeof(npcs)) 
                for(int i2 = 0; i2 < sizeof(npcs); i2++ ) {
                        npcs[i2]->remove_all_enemy(1);
                        destruct(npcs[i2]);
                }
        }
        set("usrscount", sizeof(allusrs), this_object());
        set("allusrs", allusrs, this_object());
        for(int i = 0; i < sizeof(allusrs); i++ ) {
                lv = query("level", allusrs[i]);
                if (lv > query("level_max"), this_object()) set("level_max", lv, this_object());
        }
}

int c_ghost(int blv, int si)
{
        object npc;
        int tsi;
                for(int i = 0; i < (23 - blv * 2); i++ ) {
                        npc = new(__DIR__"yuanjiang/npc/ghost");
                        tsi = si / 10 + random(si) + 1;
                        if (tsi > 999) tsi = 999;
                //      DEBUG_CHANNEL("��ɽ�Ͷ��ˮ��ȼ���" + (string)tsi);
                        set("guarder_level", tsi, npc);
                        npc->do_copyskill();
                        //npc->move(get_object(__DIR__"yuanjiang/chuan" + (string)random(50)));
                        npc->move(get_object(__DIR__"yuanjiang/chuancenter"));
                }
        return 1;
}

int c_liu()
{
        object t, npc, room;
    mapping exits;
        string *dirs, direction, to_go_place;

        t = query("top_usr");
        if (!t || !objectp(t)) return 1;
        room = environment(t);
        if (!room || !objectp(room) || strsrch(base_name(room), "teleport/yuanjiang/chuan")==-1) return 1;
        
        if( !mapp(exits=query("exits", room)))return 1;
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        to_go_place=query("exits/"+direction, room);
        room = get_object(to_go_place);
        if (!room || !objectp(room) || strsrch(base_name(room), "teleport/yuanjiang/chuan")==-1) return 1;
        npc = new(__DIR__"yuanjiang/npc/liu");
        npc->move(room);
        return 1;
}

int yuanci_attack(object me)
{
                        mapping my;
                        object room;
                        int swap, iyca;
                
                        room = environment(me);
                        if (!room || !objectp(room) || strsrch(base_name(room), "teleport/yuanjiang/chuan")==-1) return 1;
                        
                        iyca = query_temp("jinchuan/iyca", me) * query_temp("jinchuan/iyca", me) * query_temp("jinchuan/iyca", me) + 1;
                        set_temp("jinchuan/iyca", iyca, me);
                        message_vision( NOR + HIY "��ɽ�"HIW"�ײ��˵�һ�죬һ������֮����ס��$N��������$N�ƺ�һ���������������������ˡ�\n\n" NOR, me);
                        if (!random(5) && !me->is_weak()) {
                                message_vision(NOR CYN "$N" BLU "����������ѹס����������������\n", me);
                                me->set_weak(28, 0);
                        }
                        if (!random(7) && !me->query_condition("no_perform")) {
                                message_vision(NOR CYN "$N" BLU "�澭������������ס���޷�ʩչ���С�\n", me);
                                me->apply_condition("no_perform", 16);
                        }
                        my = me->query_entire_dbase();
                        my["eff_jing"] = my["eff_jing"] / (4+query("gcjinchuan_ene",me));
                        my["eff_qi"] = my["eff_qi"] / (4+query("gcjinchuan_ene",me));
                        swap = my["eff_qi"];
                        my["qi"] = my["eff_qi"] = my["eff_jing"];
                        my["jing"] = my["eff_jing"] = swap;
//                         if (my["eff_jing"] > my["eff_qi"]) my["eff_jing"] = my["eff_qi"];
//                         else my["eff_qi"] = my["eff_jing"];
                        if (my["eff_qi"] < 2000000 * iyca || my["eff_jing"] < 1000000 * iyca) {
                                set_temp("die_reason", NOR + "��Ԫ��ˮ�۵ĵط������ѹ����" + NOR, me);
                                my["qi"] = my["eff_qi"] = -1;
                                my["jing"] = my["eff_jing"] = -1;
                        }
                        if(!me->is_busy()) me->start_busy(1);
                        return 1;
}

int c_niuren(object me)
{
        object niu, ob, *obs;
        object r = get_object(__DIR__"18niuren");
        object room;
        int idx;
        
        if (!me || !objectp(me)) return 1;
        if (!r || !objectp(r)) return 1;
        if (query("level", me) < 150) return 1;
        idx = random(30-query("gcjinchuan_ene",me));
        room = environment(me);
        if (!room || !objectp(room) || strsrch(base_name(room), "teleport/yuanjiang/chuan")==-1) return 1;
        if (random(12-query("gcjinchuan_ene",me))!=0) return 1;
        r->chktop();
        obs = query("toplist", r);
        if (!obs[idx]) return 1;
        ob = new (__DIR__"npc/niuren");
        set("in_pkd", 1, ob);
        if (ob->do_copy(obs[idx])) {
                set("lifetime", time() + 180, ob);
                ob->move(environment(me));
                if (!random(4)) {
                        niu = new (__DIR__"npc/qingniu");
                        niu->move(environment(ob));
                        niu->set_leader(ob); 
                        set("title", NOR + ob->name(1) + "��" + NOR, niu);
                }
                ob->kill_ob(me);
        } else {
                destruct(ob);
        }
        return 1;
}

int deploy()
{
        string msg;
        object book, box, door, ds, room, usr, npc, *allusrs;
        int booki, yca, addnneili, cint, uc, tsi, si, blv = query("blv", this_object());
        if (!blv) {//���´�
                if (query("cusr_name")) {
                        CHANNEL_D->channel_broadcast("rumor", "��˵" + query("cusr_name") + "������֣���ɣ����Ե�����Ԫ���Ĺ�ɽ𴬡�\n");
                        blv = 8;
                } else {
                        CHANNEL_D->channel_broadcast("chat", "֣����(zheng dianxian)���Ѿ��赽������̹�ɽ𴬣��������������Ƿ�����ɽ��");
                        blv = 10;
                        get_object("/u/redl/teleport/yuanjiang/npc/xiao")->move(this_object());
                }
                set("gcjinchuan_time", time() / 86400);
                set("top_usrlv", 1);
                delete("top_usr");
                delete("cusr_name");
                __DIR__"yuanjiang/concatroom.c"->start();
                door = get_object("/u/redl/teleport/yuanjiang/npc/obj/door");
                if (objectp(door)) {
                        delete("touch_num", door);
                        delete("tele_num", door);
                        delete("attackers", door);
                        delete("drop_num", door);
                        door->move(get_object(__DIR__"yuanjiang/chuan" + (string)random(50)));
                        set("exits/out"  , __DIR__"yuanjiang/chuan" + (string)random(50) , environment(door));
                } else {
                        return 1;
                }
        }
        else blv -= 1;
        
        if (blv == 9) {
                if (!random(3) && environment(get_object("/u/redl/teleport/yuanjiang/npc/xiao"))==this_object())
                        get_object("/u/redl/teleport/yuanjiang/npc/xiao")->deploy();
        }
        
        countheads();
        set("blv", blv, this_object());
        uc = query("usrscount", this_object());
        if (blv < 8 && uc < 1) {
                CHANNEL_D->channel_broadcast("news", HIG "��˵ȥ��ɽ���Ѱ��������Ѿ�ȫ����û��");
                delete("blv");
                return 1;
        }
        
        allusrs = query("allusrs");
        foreach(usr in allusrs) {
                tell_object(usr, HIW "\n���⴫��֣���ɵ�һ����ȣ���˿�ƺ����в����������󴬻������³�ȥ��\n\n" NOR);
                usr->start_busy(2);
                if (query("level", usr) > query("top_usrlv", this_object())) {
                        set("top_usrlv", query("level", usr), this_object());
                        set("top_usr", usr, this_object());
                }
                call_out("c_niuren", 10+random(50), usr);
        }
        
        if (allusrs && uc) {
                if (uc > 1) {//Ԫ�������������
                        yca = uc / 2 + 3 - blv/2;
                        for(int iyc = 0; iyc < yca; iyc++ ) {
                                ds = allusrs[random(sizeof(allusrs))];
                                call_out("yuanci_attack", 11 + iyc, ds);
                        }
                }
                
                if (blv == 7) {
                        for(int boxi = 0; boxi < uc*uc; boxi++ ) {
                                box = new(__DIR__"yuanjiang/npc/obj/box");
                                box->move(get_object(__DIR__"yuanjiang/chuan" + (string)random(50)));
                        }
                                                box = new("/u/redl/teleport/npc/obj/qkfz");
                                                box->move(get_object(__DIR__"yuanjiang/chuan" + (string)random(50)));
                }
                
                booki = 2400 - (time() / 86400 / 7);//�ֶ��ó��ģ����Ƚ����������2���ڵ�����Żݽ����������½���ֱ��1��Ϊֹ
                if (booki < 1) booki = 1;
                booki = booki * uc * 10;
                for(int booki2 = 0; booki2 < booki; booki2++ ) {
                                                book = new("/d/dongtian/obj/wanxiangbook");
                                                book->move(get_object(__DIR__"yuanjiang/chuan" + (string)random(50)));
                }
        }
        
        if (blv>0) {
                if (blv < 8) {
                        usr = allusrs[random(sizeof(allusrs))];
        //              DEBUG_CHANNEL("��ɽ��ѷ������ң�" + query("id", usr));
                        tell_object(usr, HIW "�����ﱬ�������𵴣�һ��������������зɽ���������Ͻ�������������һ����\n" NOR);
                        CHANNEL_D->channel_broadcast("news", HIG "��˵" + HIC + query("name", usr) + HIG + "�ڽ���õ���һ��" HIY "��ɽ�"HIG"��");
                        GIFT_D->delay_bonus(usr, ([ "exp" : 15000000, "pot" : 5000000, "mar" : 2000000, "prompt" : "�������¹�ɽ�֮��"]));
                        cint = query("gift/gcjindan", usr);
                        if (cint<6) {
                                if (random(8<<(cint-1))==0) {
                                        addn("int", 1, usr); 
                                        addn("gift/gcjindan", 1, usr); 
                                        tell_object(usr, HIC "������"HIY"��ɽ�"HIC"��������������ߣ��㡣\n" NOR);
                                        CHANNEL_D->channel_broadcast("news", HIG "��˵" + HIY + query("name", usr) + HIG + "����" HIY "��ɽ�"HIG"��������������ߣ��㡣\n");
                                } else {
                                        if (random(2))
                                                tell_object(usr, HIC "�����µ����"HIY"��ɽ�"HIC"�ƺ�û�в���Ч����\n" NOR);
                                        else {
                                                addnneili = 20000 - query("gcjinchuan_neili", usr);
                                                if (query("gcjinchuan_neili", usr)<18000) addn("gcjinchuan_neili", 100, usr);
                                                addnneili = addnneili / 10 * 9 + random(addnneili / 10);
                                                tell_object(usr, HIC "��Ķ�����������������"HIY+chinese_number(addnneili)+HIC"�㡣\n" NOR);
                                                addn("drug_addneili", addnneili, usr); 
                                        }
                                }
                        } else {
                                        if (!random(3))
                                                tell_object(usr, HIC "�����µ����"HIY"��ɽ�"HIC"�ƺ�û�в���Ч����\n" NOR);
                                        else {
                                                addnneili = 20000 - query("gcjinchuan_neili", usr);
                                                if (query("gcjinchuan_neili", usr)<18000) addn("gcjinchuan_neili", 100, usr);
                                                addnneili = addnneili / 10 * 9 + random(addnneili / 10);
                                                tell_object(usr, HIC "��Ķ�����������������"HIY+chinese_number(addnneili)+HIC"�㡣\n" NOR);
                                                addn("drug_addneili", addnneili, usr); 
                                        }
                        }
                }
                
                si = (query("level_max") - query("level_min")) / 5 * (11 - blv) * 175 / 100;
                if ( blv == 7 && query("top_usrlv")>300 && !random(4) && uc>2 ) call_out("c_liu", 3);
                call_out("c_ghost", 10, blv, si);
                if (!random(3)) {
                        door = get_object("/u/redl/teleport/yuanjiang/npc/obj/door");
                        tell_room(environment(door), NOR + door->name() + NOR + "���˸����磬��Ȼ��������ֻ�ţ��������ˡ�\n" NOR);
                        door->move(get_object(__DIR__"yuanjiang/chuan" + (string)random(50)));
                        set("exits/out"  , __DIR__"yuanjiang/chuan" + (string)random(50) , environment(door));
                }
                remove_call_out("deploy");
                if (blv < 8) call_out("deploy", 120 + blv * 5);
                        else call_out("deploy", 180);
                        
                return 1;
        }
        
        //DEBUG_CHANNEL("��ɽ𴬳�û����Ҵ������" + (string)uc);
        foreach(usr in allusrs) {
                if (!msg) msg = NOR + HIC + query("name", usr) + NOR;
                else msg += HIG "��" + NOR + HIC + query("name", usr) + NOR;
                tell_object(usr, HIW "֣���ɴ��һ��������~������һ�����飬�����Ṧ���ذ��ϣ�ֻ���޴���¡��¡�������׳�ȥ��\n" NOR);
                //usr->move(query("exits/out", this_object()));
                usr->move(this_object());
                addn("weiwang", -100000, usr);
                tell_object(usr, NOR "����Ԫ���ᱦʧ�ܣ��㱻�۳�ʮ��㽭��������\n"+ NOR); 
        }
        msg = sort_msg( HIG "��˵�������ߣ���ɽ����³�û��" + msg + HIG "�����ӳ����졣" + NOR);
        CHANNEL_D->channel_broadcast("news", msg);
        for(int i = 0; i < 50; i++ ) {
                room = get_object(__DIR__"yuanjiang/chuan" + (string)i);
                if (room && objectp(room)) destruct(room);
        }
        delete("blv", this_object());
        return 1;
}

int cdeploy(object me)
{
        set("cusr_name", query("name", me), this_object());
        //call_out("deploy", 1);
        deploy();
}

int valid_leave(object me, string dir)
{
        if (!interactive(me) || !playerp(me)) return 0;
                if (dir=="wiz" && wiz_level(me) < 3) {
                                tell_object(me, NOR + "�㲻��������ͨ����������ѯ(ask zheng all)��\n" + NOR); 
                return -1;
        }
        return ::valid_leave(me, dir);
}


