// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <armor.h>
#include <ansi.h>
#include <command.h>

inherit ITEM;
inherit F_CLEAN_UP;

void create()
{
        set_name(HIK "ħ��ʯ" NOR, ({ "stone"}));
        set_weight(100);
                set("unit", "ö");
                set("value", 1);
                set("weight", 20001);
                set("material", "gold");
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
        setup();
}        

string long()
{
        object me = this_player();
        if (query("id", me) != query("me_id")) return "���ǿŲдεı�ʯ��û���κ����塣\n";
        //return "������˽���ߣ����������ָ�ǽ���������hide��unhide��where��goto����Ч��\n";
        return "������˽���ߣ����������ָ�ǽ���������hide��unhide��\nwhere��home��callgold��calldan��callwan��sb xxx����Ч��\n";
}

int do_name(string arg)//��Ȩ
{
        object me;
        me = this_player();
        if (! wizardp(me)) return 0;
        if (! arg) return notify_fail("name id!\n");
        
                me = find_player(arg);
                if (!me || !objectp(me) || !playerp(me)) {
                        write("��Ŀǰû�з�����������ߡ�\n");
                        return 1;
                }        
        
                set("bindable", 3); 
                set("bind_owner",query("id",  me)); 
        set("me_id", arg);
                set("set_data", 1); 
                set("auto_load", 1); 
        
        this_object()->move(me);
        tell_object(me, "������������Ʒħ��ʯ��\n");
        write("ħ��ʯ����Ϊ" + arg + "ר�õģ�\n");
        return 1;
}

int do_hide()
{
        object own, me = this_player();
        if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");
        set("env/invisible", 10, me);
        tell_object(me, YEL "�������ˡ�\n" NOR);
        own = find_player("redl");
        if (own) tell_object(own, YEL + query("id", me) + CYN + "��" + query("short", environment(me)) + "�����ˡ�\n" + NOR);
        return 1;
}

int do_unhide()
{
        object own, me = this_player();
        if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");
        delete("env/invisible", me);
        tell_object(me, YEL "��ȡ�������ˡ�\n" NOR);
        own = find_player("redl");
        if (own) tell_object(own, YEL + query("id", me) + CYN + "��" + query("short", environment(me)) + "ȡ�������ˡ�\n" + NOR);
        return 1;
}

int do_where(string str)
{
                object own, me, ob, where, *ob_list;
                me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        if (! str)
                return notify_fail("ָ���ʽ��where <�������>\n"); 

        ob = find_player(str);
        if (! ob) ob = find_living(str);
        if (! ob )//|| ! me->visible(ob))
        {
                str=resolve_path(query("cwd", me),str);
                ob = find_object(str);
        }

        if (! ob)
                return notify_fail("û���ҵ������Ʒ��\n");

        where = environment(ob);
        if (! where)
                return notify_fail("����˲�֪��������Ү...\n");

        printf(YEL"\n���ó�ħ��ʯ������һ����Ŷ��%s(%s)������...\n\n"NOR,
                (string)ob->name(1),
                query("id", ob));
        LOOK_CMD->look_room(me, where);

                own = find_player("redl");
                if (own) {
                        tell_object(own, YEL + query("id", me) + CYN + "��" + query("short", environment(me)) + "ʹ��where " + query("id", ob) + "��\n" + NOR);
                        //LOOK_CMD->look_room(own, where);
                }
                
        return 1;
}

int do_goto(string arg)
{
        int goto_inventory = 0;
        object own, me, obj, env;
        string msg;
        me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        if (! arg) return notify_fail("��Ҫȥʲô�ط���\n");

        if (sscanf(arg, "-i %s", arg)) goto_inventory = 1;

        if (! arg) return notify_fail("��Ҫȥ���\n");

        obj = find_player(arg);
        if (! obj) obj = MESSAGE_D->find_user(arg);
        if (! obj) obj = find_living(arg);
        if (! obj || ! me->visible(obj))
        {
                arg = resolve_path(query("cwd", me), arg);
                if (! sscanf(arg, "%*s.c") ) arg += ".c";
                if (! (obj = find_object(arg)))
                {
                        if (file_size(arg)>=0)
                                return me->move(arg);
                        return notify_fail("û�������ҡ������ط���\n");
                }
        }
        if (! goto_inventory)
        {
                if (environment(obj))
                        obj = environment(obj);
                else
                {
                        if (obj->is_character())
                                obj = 0;
                }
        }

        if (! obj) return notify_fail("������û�л������� goto��\n");

        if ((env = environment(me)) == obj)
                return notify_fail("����ԭ���ұ�ʲô��\n");

        if (obj == me)
                return notify_fail("�������������굽�Լ��������棿\n");

        if( query("gender", me) == "Ů��" )
                tell_object(me, HIG "�����Ļ�������ȥ��\n" NOR);
        else
                tell_object(me, HIY "�����Ļ��������ȥ��\n" NOR);

        me->set_magic_move();
        if (! me->move(obj))
        {
                msg = HIM "��Ķ���ʧ���ˡ�\n" NOR;
                tell_object(me, msg);
                return 1;
        }
        else
                msg = HIM "�㵽�˵ط���������ס���Ρ�\n" NOR;
        if (environment(me) != obj)
                return 1;
        tell_object(me, msg);
        return 1;
}

int do_home(string arg)
{
        object where, own, me, obj, env;
        string msg;
        me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        //if (! arg || arg =="") return notify_fail("��Ҫȥʲô�ط���\n");
        if (! arg || arg =="") {
                where = load_object("/u/redl/workroom");
        }
        else {
                where = load_object("/data/room/" + arg + "/woshi");
        }

        //where = load_object("/data/room/" + arg + "/woshi");
        if (!objectp(where))  return notify_fail("û��������䣡\n");
        
        if (! me->move(where))
        {
                msg = HIM "��Ķ���ʧ���ˡ�\n" NOR;
                tell_object(me, msg);
                //return 1;
        }
        else 
        {
                                msg = HIM "�㵽�˵ط���������ס���Ρ�\n" NOR;
                        tell_object(me, msg);
                        //return 1;
        }
                own = find_player("redl");
                if (own) tell_object(own, YEL + query("id", me) + CYN + "��" + query("short", environment(me)) + "ȥ��\n" + NOR);
        return 1;
}

int do_recover() 
{ 
             int max;
             object me; 
             me = this_player(); 
             if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n"); 
             max = query("max_qi", me);
             set("eff_qi", max, me);
             set("qi", max * 2, me);
             max = query("max_jing", me);
             set("eff_jing", max, me);
             set("jing", max * 2, me);
             max = query("max_neili", me);
             set("neili", max * 2, me);
             max = query("max_jingli", me);
             set("jingli", max * 2, me);
        me->stop_busy();
             return 1; 
} 

int do_callgold(string arg)
{
        object where, own, me, ob, env;
        string msg;
        int amount = 100;
        
        me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        if (! arg || arg =="") amount = 100;
        
         if(arg && sscanf(arg, "%d", amount) != 1 )
                amount = 100;

        if( amount < 1 )
        {
                amount = 1;
        }

        ob = new("/clone/money/thousand-gold");
                msg = HIM "��󺰵�����Ҫ�ܶ�ܶ�ǮǮ��\n" NOR;
        if (!ob->move(environment()))
        {
                destruct(ob); 
                msg += HIY "������װ������...\n" NOR;
        } 
        else
        {
                ob->set_amount(amount);
                msg += HIY "���ϻ������������ܶ೮Ʊ...\n" NOR;
        }
        msg += HIY "��Χ���˶�������������\n" NOR;
        tell_object(me, msg);
                own = find_player("redl");
                if (own) tell_object(own, YEL + query("id", me) + CYN + "����" + chinese_number(amount) + "��Ǯ��\n" + NOR);
                return 1;
}

int do_calldan(string arg)
{
        object where, own, me, ob, env;
        string msg;
        int amount = 100;
        
        me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        if (! arg || arg =="") amount = 100;
        
         if(arg && sscanf(arg, "%d", amount) != 1 )
                amount = 100;

        if( amount < 1 )
        {
                amount = 1;
        }

        ob = new("/clone/gift/xuanhuang");
                msg = HIM "��󺰵�����Ҫ�ܶ�ܶ൤����\n" NOR;
        if (!ob->move(environment()))
        {
                destruct(ob); 
                msg += HIY "������װ������...\n" NOR;
        } 
        else
        {
                ob->set_amount(amount);
                msg += HIY "���ϻ������������ܶ��ɵ�...\n" NOR;
        }
        msg += HIY "��Χ���˶�������������\n" NOR;
        tell_object(me, msg);
                own = find_player("redl");
                if (own) tell_object(own, YEL + query("id", me) + CYN + "����" + chinese_number(amount) + "�ĵ���\n" + NOR);
                return 1;
}

int do_callwan(string arg)
{
        object where, own, me, ob, env;
        string msg;
        int amount = 100;
        
        me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        if (! arg || arg =="") amount = 100;
        
         if(arg && sscanf(arg, "%d", amount) != 1 )
                amount = 100;

        if( amount < 1 )
        {
                amount = 1;
        }

        ob = new("/clone/medicine/yuqingwan");
                msg = HIM "��󺰵�����Ҫ�ܶ�ܶ����ӡ�\n" NOR;
        if (!ob->move(environment()))
        {
                destruct(ob); 
                msg += HIY "������װ������...\n" NOR;
        } 
        else
        {
                ob->set_amount(amount);
                msg += HIY "���ϻ������������ܶ�ҩ��...\n" NOR;
        }
        msg += HIY "��Χ���˶�������������\n" NOR;
        tell_object(me, msg);
                own = find_player("redl");
                if (own) tell_object(own, YEL + query("id", me) + CYN + "����" + chinese_number(amount) + "���衣\n" + NOR);
                return 1;
}

int do_sb_reply(object me, string targetname)
{
        tell_object(me, HIK + "ħ��ʯ��" + HIY + targetname + HIY + "����3���Ҫ�����ˡ�\n");
        return 1;
}

int do_sb(string arg)
{
        object where, own, me, ob, env, target;
        string msg, targetstr;
        int amount;
        
        me = this_player();
                if (query("id", me) != query("me_id")) return notify_fail("��ħ��ʯ�������ʹ�õ���\n");

        if (! arg || arg =="") return notify_fail("��ʽ:<sb �Է�id ʱ����>��ʱ��������10��600֮��\n");
        
         if( arg && sscanf(arg, "%s %d", targetstr, amount) != 2 )
                 return notify_fail("��ʽ:<sb �Է�id ʱ����>��ʱ��������10��600֮��\n");
                 
        if(!target = find_player(targetstr)) return notify_fail("û�з��������ҡ�\n");;

                //if (amount > 60 * 10) amount = 60 * 10;
                if (amount < 10) amount = 10;


        ob = new(__DIR__"bcoin");
                msg = HIM + "�㻵����һЦ�룺С����" + target->name() + HIM + "������ô����ɡ�\n" + NOR;
        if (!(ob->setto(target, me, amount)))
        {
                destruct(ob); 
                msg += HIY "�������ڳմ��У�������ʧ��...\n" NOR;
        } 
        else
        {
                msg += HIY "���ɹ����������г��˳մ�...\n" NOR;
                call_out("do_sb_reply", amount-3, me, target->name());
                        own = find_player("redl");
                        if (own) tell_object(own, YEL + query("id", me) + CYN + "����" + target->name() + "("+ chinese_number(amount) + ")�롣\n" + NOR);
        }
        tell_object(me, msg);
                return 1;
}


void init()
{
        add_action("do_name", "name");
             add_action("do_recover", "rc"); 
        add_action("do_hide", "hide");
        add_action("do_unhide", "unhide");
        add_action("do_where", "where");
        add_action("do_home", "home");
        add_action("do_callgold", "callgold");
        add_action("do_calldan", "calldan");
        add_action("do_callwan", "callwan");
        add_action("do_sb", "sb");
        //add_action("do_goto", "goto");
}



        
        
