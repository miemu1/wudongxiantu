// This program is a part of NITAN MudLIB 
// redl 2013/11
#include <ansi.h>
#include <skill.h>

inherit ITEM;
inherit F_CLEAN_UP;
#define SKILLS_D	"/adm/daemons/skillsd"
mapping *booklists = ({
                (["id":"guangming-jing",
                        "tname":"���ƹ�����",
                        "rate":1000,
                       // "fam":"����"
                        ]),
                (["id":"cibei-dao",
                        "tname":"�ȱ���",
                        "rate":1000
                        ]),
                (["id":"cuixin-zhang",
                        "tname":"������",
                        "rate":1000
                        ]),
                (["id":"literate",
                        "tname":"����д��",
                        "rate":1000
                        ]),
                (["id":"luohan-quan",
                        "tname":"�޺�ȭ",
                        "rate":1000
                        ]),	
				(["id":"shenxing-baibian",
                        "tname":"���аٱ�",
                        "rate":1000
                        ]),
				(["id":"force",
                        "tname":"�ڹ�",
                        "rate":1000
                        ]),
						
        });


void create()
{
        set_name(NOR BRED YEL "��" NOR BRED HIW "��������" NOR BRED YEL "��" NOR, ({"wanxiang book", "book"}));
        set_weight(5);
                set("unit", "��");
                set("value", 1000);
                set("weight", 5);
				set("yuanbao", 5);
                set("material", "paper");
                set("longx", "���Ǳ������ޱȵ��鼮������ǧ�򣬿��Դ�(open book)���ԡ�\n");
                set("set_data", 1); 
                set("auto_load", 1); 
                set("no_sell", 1);
               // set("no_pawn", 1);        
                setup();
        if (query("opened")) {
                set_name(query("opened/name"), ({ query("opened/skill") + " book", "wanxiang book", "book"}));
                switch(query("opened/type")) {
                        case 1:
                                set("longx", "����һ����ѧ���ţ���(read)�����ѧ�ᡸ"+query("opened/can_perform")+"����ʹ�þ��ϡ�\n");
                                break;
                        case 2:
                                set("longx", "����һ����ѧ���ţ���(read)�������ߡ�"+query("opened/tname")+"������Ϊ��\n");
                                break;
                        case 3:
                                set("longx", "����һ�������ؼ�����(read)�������ߡ�"+query("opened/tname")+"����֪ʶ��\n");
                                break;
                }
        }
}        

string long()
{
        return query("longx");
}

int do_open(string arg)
{
        int i, k, rate, *rates = ({}), totalrate = 0, rndrate;
        string oldname, pfmpath, *pfmfs = ({}), rndpfm, *tname = ({}), *skid = ({});
        mixed *pfmfiles;
        mapping b;
        object me = this_player();
        
        if (!arg || (arg!=query("id") && arg!="book")) return 0;
        
        if (!query("no_open_msg") && me && playerp(me) && wiz_level(me) < 5) {
                me->start_busy(1);
        }

        if (query("opened")) return notify_fail(NOR "�Ȿ���Ѿ����˰����ú��о�(look)���ɡ�\n" NOR);

        oldname = query("name");
        
        for(i=0; i<sizeof(booklists); i++) {
                rate = booklists[i]["rate"];
                totalrate += rate;
                rates += ({rate});
                tname += ({booklists[i]["tname"]});
                skid += ({booklists[i]["id"]});
        }
        
        rndrate = random(totalrate);
        totalrate = 0;
        
        for(i=0; i<sizeof(rates); i++) {
                //write("totalrate:" + (string)totalrate + "\n");
                if (rndrate >= totalrate && rndrate < (totalrate + rates[i])) {
                        set("opened/skill", skid[i]);
                        set("opened/tname", tname[i]);
                        if (booklists[i]["fam"]) set("opened/fam", booklists[i]["fam"]);
                        if ( (string) SKILL_D(skid[i])->type() == "martial" ) {
                                if (!booklists[i]["no_learn_pfm"]) {
                                        pfmpath = "/kungfu/skill/" + skid[i] + "/";
                                        if (SKILL_D(skid[i])->valid_enable("force")) pfmpath += "perform/";
                                }
                                if (pfmpath && file_size(pfmpath) == -2) {
                                        pfmfiles = get_dir(pfmpath, -1);
                                        if (pfmfiles && sizeof(pfmfiles)) {
                                for (k = 0; k < sizeof(pfmfiles); k++)
                                {
                                        if (pfmfiles[k][0][strlen(pfmfiles[k][0])-2..strlen(pfmfiles[k][0])] != ".c")
                                                                                     continue;
                                        pfmfs += ({replace_string(pfmfiles[k][0], ".c", "")});
                                }
                                                if (pfmfs && sizeof(pfmfs)) rndpfm = pfmfs[random(sizeof(pfmfs))];
                                        }
                                }
                                if (random(25)==0 && rndpfm) {//��С���ʣ��������������һ��pfm�������
                                        set("opened/name", NOR+YEL+"��"+YEL+tname[i]+NOR+YEL+"��"+YEL+"����"+NOR+YEL+"��"+NOR);
                                        set("longx", "����һ����ѧ���ţ���(read)�����ѧ�ᡸ"+rndpfm+"����ʹ�þ��ϡ�\n");
                                        set("opened/type", 1);
                                        set("opened/can_perform", rndpfm);
                                } else {
                                        set("opened/name", NOR+YEL+"��"+WHT+tname[i]+NOR+YEL+"��"+WHT+"����"+NOR+YEL+"��"+NOR);
                                        set("longx", "����һ����ѧ���ţ���(read)�������ߡ�"+tname[i]+"������Ϊ��\n");
                                        set("opened/type", 2);
                                }
                        } else {
                                set("opened/name", NOR+YEL+"��"+CYN+tname[i]+NOR+YEL+"��"+CYN+"�ؼ�"+NOR+YEL+"��"+NOR);
                                set("longx", "����һ�������ؼ�����(read)�������ߡ�"+tname[i]+"����֪ʶ��\n");
                                set("opened/type", 3);
                        }
                        break;
                }
                totalrate += rates[i];
        }
        set_name(query("opened/name"), ({ skid[i] + " book", "wanxiang book", "book"}));
        if (!query("no_open_msg")) message_vision(NOR + CYN + "$N" + NOR + CYN + "��"+ oldname + NOR + CYN + "�����һ��" +query("name") + NOR + CYN + "��\n" + NOR, me);
        return rates[i];
}

int do_read(string arg)
{
        object me = this_player();
        string sks, pfm;
        int flagused = 0, diff, improve = 3000000;
        int pot = 100000;
                
        if (!arg || (arg!=query("id") && arg!="book")) return 0;

        if (me && playerp(me) && wiz_level(me) < 5) {
                me->start_busy(1);
        }
        
        if (!query("opened")) return notify_fail(NOR "������������鰡����(open)���ж��ɡ�\n" NOR);
        
        if ( query("opened/type") == 1 && ( (me->query("potential")-me->query("learned_points"))<100000000 ) )
                return notify_fail(NOR "������������ѧϰ������Ҫ���ڵ�Ǳ�ܡ�\n" NOR);
        else if ( query("opened/type") == 2 && ((me->query("potential")-me->query("learned_points"))<1000000 ) )
                return notify_fail(NOR "�Ķ���������ѧϰ�书������Ҫ���������Ǳ�ܡ�\n" NOR);
        else if ((me->query("potential")-me->query("learned_points"))<1000 )
                return notify_fail(NOR "�Ķ���������ѧϰ֪ʶ������Ҫ����������Ǳ�ܡ�\n" NOR);
        
        sks = query("opened/skill");
        
        improve *= (me->query("int") / 5) + 12;//�Ѳ��ԣ�����40int��idҪ�ﵽ150level��û��diff��Ҳ��Ҫ��12��
                switch(query("opened/type")) {
                        case 1:
                                pfm = query("opened/can_perform");
                                if ( me->query_skillo(sks, 1)>149 ) {
                                        me->set("can_perform/" + sks + "/" + pfm, 1);
                                        tell_object(me, NOR + "��ڤ˼���룬���ڴ�����������ϰ���ˡ�"+pfm+"���ľ�����\n" + NOR);
                                        me->addn("potential", -100000000);
                                        flagused = 1;
                                } else {
                                        tell_object(me, NOR + "�㻹���ᡸ"+query("opened/tname")+"�����ߵ��ڣ��������� \n" + NOR);
                                }
                                break;
                        case 2:
                                        diff = SKILLS_D->query_skill_difficult(sks); 
                                        if (! diff) diff = SKILL_D(sks)->difficult_level(); 
                                        improve = improve / (300 + diff); 
                                        if (improve < 500) improve = 500; 
                                        if (!me->can_improve_skill(sks)) {
                                                write(NOR + "Ҳ����ȱ��ʵս��Ϊ����е����Լ����о���" + query("opened/tname") + "���������ˡ�\n" + NOR); 
                                        } else if (query("opened/fam") && query("opened/fam")!=me->query("family/family_name")) {
                                                write(NOR + "ֻ��" + query("opened/fam") + "�ĵ��Ӳ����о���" + query("opened/tname") + "����\n" + NOR); 
                                        } else {
                                                me->improve_skill(sks, improve); 
                                                write(NOR "���о���һ�ᣬ�ƺ��ԡ�"+query("opened/tname")+"����Щ�µ�����\n" + NOR); 
                                        me->addn("potential", -1000000);
                                                flagused = 1;
                                        }
                                break;
                        case 3:
                                if (query("opened/fam") && query("opened/fam")!=me->query("family/family_name")) {
                                                write(NOR + "ֻ��" + query("opened/fam") + "�ĵ��Ӳ���ѧϰ��" + query("opened/tname") + "����\n" + NOR); 
                                        } else if ( me->query_skillo(sks, 1)<5000 || sks=="literate" ) {
                                                me->improve_skill(sks, improve / 800); 
                                                write(NOR "���о���һ�ᣬ�ƺ��ԡ�"+query("opened/tname")+"����Щ�µ�����\n" + NOR); 
                                        me->addn("potential", -1000);
                                                flagused = 1;
                                } else {
                                        tell_object(me, NOR + "��ġ�"+query("opened/tname")+"�������ˣ������������Ѿ��޷��ٴ�����������ѧϰ�ˡ� \n" + NOR);
                                }
                                break;
                }
    if (flagused) {
        message_vision(NOR + CYN + "$N" + NOR + CYN + "�����" +query("name") + NOR + CYN + "һ��Ϊ�ɻҡ�\n" + NOR, me);             
        destruct(this_object());
    }
        return 1;
}

int do_setsk(string arg)
{
        if (!arg) return notify_fail(NOR "Ҫ����ʲôskill��\n" NOR);
        set("opened/skill", arg);
        set("opened/tname", arg);
        set("opened/type", 2);
        set("longx", "����һ�������õ���ѧ���ţ�(read book)\n");
        set_name("��������", ({"book"}));
        write("ok\n");
        return 1;
}

void init()
{
        add_action("do_open", "open");
        add_action("do_read", "read");
        if (wiz_level(this_player()) > 5) 
                add_action("do_setsk", "setsk");
}


