// /adm/daemons/faction.c ���NPC���ܹ����ػ�����
// By Alf, Last Update 2003.0722
// Ŀǰ�ɹ�ɱ�ּ���Ժ����

#include <ansi.h>
#include "include/faction.h"

public mapping *query_all_skill();              //�������м�������б�
public int show_skill(object me, string arg);   //��ѯ���趨���ܵ����
public void gen_npc(object me, string arg);     //���趨������������
public void ran_skill(object me, string arg);   //���б���ָ�������ѡ��ĳ�ּ���
public void gen_skill(object me);               //����ѡ���Ĳ����趨�����书����
public void gen_dbase(object me);               //�趨�Ա����徫�������ȸ�������
public void gen_items(object me);               //��������������ƥ�ȸ���Я����Ʒ

//�������м�������б�
public mapping *query_all_skill()
{
    return all_skill;
}

//��ѯ���趨�������
public int show_skill(object me, string arg)
{
    int i, j;
    string gen, msg;

    if(!arg || arg == "")   //�޲�����ʾȫ��
    {
        msg  = HIC "\n��ǰ�ɹ�ѡ��ļ����У�\n" NOR;
        msg += HIG "----------------------------------------------------\n" NOR;
        j = sizeof(all_skill);
        for(i = 0; i < j; i++)
        {
            if(all_skill[i]["no_list"])
            {
                j -= 1;
                continue;
            }
            if(!weapon_type[all_skill[i]["weapon"]])
                weapon_type[all_skill[i]["weapon"]] = "�书";
            msg += sprintf(HIW "���ƣ�" HIY "%-12s" NOR
                           HIW "���ɣ�" HIG "%-8s" NOR
                           HIW "���ͣ�" HIC"%-6s" NOR
                           HIW "������" HIB"%-4s\n" NOR,
                           all_skill[i]["name"],
                           all_skill[i]["faction"],
                           weapon_type[all_skill[i]["weapon"]],
                           all_skill[i]["horse"] ? HIG "��" : "��");
        }
        msg += HIG "----------------------------------------------------\n" NOR;
        msg += HIC "���� "HIW + chinese_number(j) + HIC" �ּ��ܿɹ�ѡ��\n\n" NOR;
    }
    else
        if(arg) //���ղ�����ѯ����ʾ
    {
        for(i = 0; i < sizeof(all_skill); i++)
        {
            if(all_skill[i]["code"] == arg || all_skill[i]["name"] == arg)
            {
                me->set_temp("query_faction", arg);
                if(!weapon_type[all_skill[i]["weapon"]])
                    weapon_type[all_skill[i]["weapon"]] = "�书";
                msg = sprintf(HIW "\n��" HIY "%s" HIW "����" HIC "%s"
                              HIW "��һ��%s", all_skill[i]["name"],
                                              all_skill[i]["faction"],
                                              weapon_type[all_skill[i]["weapon"]]);

                if(all_skill[i]["gender"] == "all")
                    msg += "������ʹ�ö���";
                else
                {
                    if(all_skill[i]["gender"] == "male")
                        gen = "����";
                    if(all_skill[i]["gender"] == "female")
                        gen = "Ů��";
                    msg += "������"HIG + gen + HIW"ʹ��";
                }
                if(all_skill[i]["horse"] == 1)
                    msg += "����Ҫ�����ܾ���ʩչ��\n" NOR;
                else
                    msg += "�����������ɾ���ʩչ��\n" NOR;
                break;
            }
            else
                msg = "";

        }
        if(msg == "")
            msg += YEL "Ŀǰ��δ�����ּ��ܹ�ѡ��\n" NOR;
    }

    me->start_more(msg);
    return 1;
}

//���趨������������
public void gen_npc(object me, string arg)
{
    ran_skill(me, arg);
    gen_skill(me);
    gen_dbase(me);
    gen_items(me);
    return;
}

//���б���ָ�������ѡ��ĳ�ּ���
public void ran_skill(object me, string arg)
{
    int i;
    string *key;
    mapping skill = ([]);

    if(!arg)    //�޲������ѡ��һ��
    {
        for(i = 0; i < sizeof(all_skill); i++)
        {
            if(all_skill[i]["no_list"]) //�������಻�������ѡ��֮��
                continue;
            if(me->query("gender") == "����"
                && all_skill[i]["gender"] == "female")  //Ԥ���������Ա�̫���
                    continue;
            if(me->query("gender") == "Ů��"
                && all_skill[i]["gender"] == "male")  //Ԥ���������Ա�̫���
                    continue;
            skill += ([ all_skill[i]["code"] : all_skill[i]["name"], ]);
        }
        key = sort_array(keys(skill), 1);
        arg = key[random(sizeof(key))];
    }

    for(i = 0; i < sizeof(all_skill); i++)
    {
        if(all_skill[i]["name"] == arg
            || all_skill[i]["code"] == arg) //���ղ�����ѯ��ѡ��
        {
            skill = all_skill[i];
            me->set("generation_skill", skill);
            break;
        }
    }

    return;
}

//����ѡ���Ĳ����趨�����书����
public void gen_skill(object me)
{
    int i, level;
    mapping skill, m_skill, p_skill, special;
    string *key;

//ɾ��ԭ�м���
    skill = me->query_skill_prepare();
    if(!skill)
        skill = ([]);

    if(mapp(skill) && sizeof(skill) > 0)
    {
        key = keys(skill);
        for(i = 0; i < sizeof(key); i++)
        {
            me->prepare_skill(key[i]);
        }
    }

    skill = me->query_skills();
    if(mapp(skill) && sizeof(skill) > 0)
    {
        key = keys(skill);
        for(i = 0; i < sizeof(key); i++)
        {
            me->map_skill(key[i]);
            map_delete(me->query_skills(), key[i]);
        }
    }

    special = me->query("generation_skill/special");
    if(mapp(special) && sizeof(special) > 0)
    {
        key = keys(special);
        for(i = 0; i < sizeof(key); i++)
        {
            me->delete(key[i]);
        }
    }

//�趨��������
    skill = me->query("generation_skill");
    level = me->query("set_skill/level");
    if(!level)
        level = 250;
    if(level > 900)
        level = 900;

    if(mapp(skill) && sizeof(skill) > 0)
    {
        m_skill = me->query("generation_skill/m_skill");
        if(mapp(m_skill) && sizeof(m_skill) > 0)
        {
            key = keys(m_skill);
            for(i = 0; i < sizeof(m_skill); i++)
            {
                me->set_skill(key[i], level);
                me->set_skill(m_skill[key[i]], level);
                me->map_skill(key[i], m_skill[key[i]]);
            }
        }

        p_skill = me->query("generation_skill/p_skill");
        if(mapp(p_skill) && sizeof(p_skill) > 0)
        {
            key = keys(p_skill);
            for(i = 0; i < sizeof(p_skill); i++)
            {
                me->prepare_skill(key[i], p_skill[key[i]]);
            }
        }

        special = me->query("generation_skill/special");
        if(mapp(special) && sizeof(special) > 0)
        {
            key = keys(special);
            for(i = 0; i < sizeof(key); i++)
            {
                me->set(key[i], special[key[i]]);
            }
        }
    }
    me->reset_action();
    return;
}

//�趨�Ա����徫�������ȸ�������
public void gen_dbase(object me)
{
    int level = me->query("set_skill/level");
    string gender = me->query("generation_skill/gender");
    string weapon = me->query("generation_skill/weapon");
    string *gends = ({ "����", "Ů��", });
    string *nation = ({ "����", "����", });

    if(!me->query("generation_skill"))
        return;

    if(!gender || gender == "all")
    {
        if(me->query("gender"))
            me->set("gender", me->query("gender"));
        else
            me->set("gender", gends[random(sizeof(gends))]);
    }
    else
        if(gender == "male")
            me->set("gender", "����");
    else
        if(gender == "female")
            me->set("gender", "Ů��");
    else
        me->set("gender", "����");

    if(me->query("generation_skill/nation"))
        me->set("nation", me->query("generation_skill/nation"));
    else
        me->set("nation", nation[random(sizeof(nation))]);

    if(!level)
        level = 250;
    if(level > 900)
        level = 900;

    if(me->is_house_huyuan())   //��Ժ�ļ��㹫ʽ
    {
        me->set("qi", level*15);
        me->set("max_qi", level*15);
        me->set("eff_qi", level*15);
        me->set("jing", level*12);
        me->set("eff_jing", level*12);
        me->set("max_jing", level*12);
        me->set("jingli", level*18);
        me->set("max_jingli", level*18);
        me->set("neili", level*20);
        me->set("max_neili", level*20);
        me->set("jiali", level/4);
        me->set("combat_exp", (level/10)*level*level);
        me->set("set_skill/level", level);
    }
    else
        if(me->is_killer())    //ɱ�ֵļ��㹫ʽ
    {

        if(weapon == "unarmed"
            || weapon == "claw"
            || weapon == "finger")
                level = level*10/9;   //���ּ��ܵȼ��Ը�
        me->set("qi", level*5);
        me->set("max_qi", level*5);
        me->set("eff_qi", level*5);
        me->set("jing", level*4);
        me->set("eff_jing", level*4);
        me->set("max_jing", level*4);
        me->set("jingli", level*4);
        me->set("max_jingli", level*4);
        me->set("neili", level*10);
        me->set("max_neili", level*10);
        me->set("combat_exp", (level/10)*level*level);
        me->set("set_skill/level", level);
    }
    else    //Ĭ�ϵļ��㹫ʽ
    {
        me->set("qi", level*5);
        me->set("max_qi", level*5);
        me->set("eff_qi", level*5);
        me->set("jing", level*4);
        me->set("eff_jing", level*4);
        me->set("max_jing", level*4);
        me->set("jingli", level*4);
        me->set("max_jingli", level*4);
        me->set("neili", level*10);
        me->set("max_neili", level*10);
        me->set("combat_exp", (level/10)*level*level);
        me->set("set_skill/level", level);
    }

    return;
}

//��������������ƥ�ȸ���Я����Ʒ
public void gen_items(object me)
{
    int i;
    string my_weapon, file;
    object *inv, weapon, armor, horse;

    if(!me->query("generation_skill"))
        return;

    if(me->query("carry_obj"))  //ɾ���ɵ�Я����Ʒ�б�
        me->delete("carry_obj");

    inv = all_inventory(me);
    for(i = 0; i < sizeof(inv); i++)
    {
        if(inv[i]->query_autoload())
            continue;
        destruct(inv[i]);   //�ݻ�ԭ��Я����Ʒ
    }

    my_weapon = me->query("generation_skill/weapon");
    if(my_weapon != "unarmed"
        && my_weapon != "claw"
        && my_weapon != "finger")   //���м��ܴ�����Я����
    {
        if(me->query("generation_skill/code") == "xiyang")
            armor = new("/clone/misc/xifu");    //����Ӵ�����
        else
            armor  = new("/clone/misc/cloth");
        weapon = new(weapon_file[my_weapon]);
        file = base_name(weapon);
        me->set("carry_obj/weapon", file);
        if(me->query("generation_skill/code") != "xiyang")
            "/adm/daemons/x_named"->x_name(weapon, "");
        weapon->move(me);
        weapon->wield();
    }
    else    //���ּ��ܴ�����
    {
        armor = new("/clone/misc/ruankai");
    }
    file = base_name(armor);
    me->set("carry_obj/armor", file);
    armor->move(me);
    armor->wear();

    if(me->query("generation_skill/horse") == 1)    //��ս��������
    {
        horse = new("/clone/horse/huangbiao-ma");
        file = base_name(horse);
        me->set("carry_obj/horse", file);
        horse->move(me);
        horse->ride();
    }
    return;
}
