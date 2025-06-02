// itemmake.c ���Ƶ���

#include <dbase.h>
#include <ansi.h>
#include <name.h>
#include <move.h>
#include <command.h>

inherit F_OBSAVE;
inherit F_NOCLONE;

int is_item_make() { return 1; }

#define LEVEL1    5
#define LEVEL2    10
#define LEVEL3    30
#define LEVEL4    100
#define LEVEL5    300
#define LEVEL6    1000
#define LEVEL7    3000
#define LEVEL8    10000
#define LEVEL9    50000
#define MAX_LEVEL       LEVEL9
#define ULTRA_LEVEL     (LEVEL9 + 1)
#define MEMBER_D        "/adm/daemons/memberd"

#define TAOZHUANG_D     "/adm/daemons/taozhuangd"

nosave int *levels = ({ LEVEL1, LEVEL2, LEVEL3, LEVEL4,
                        LEVEL5, LEVEL6, LEVEL7, LEVEL8,
                        LEVEL9 });

nosave int performing  = 0;
nosave int attack_lvl  = 0;
nosave int defense_lvl = 0;
37      static mapping qianghua_level = ([ 
38              "1":       "��", 
39              "2":       "���", 
40              "3":       "����", 
41              "4":       "�����", 
42              "5":       "������", 
43              "6":       "�������", 
44              "7":       "��������", 
45              "8":       "���������", 
46              "9":       "����������", 
47              "10":      "�����������", 
48      ]); 

int is_stay_in_room() { return attack_lvl >= ULTRA_LEVEL; }

// n_type 0 Ϊ��Ե 1 Ϊ����
int f_enchase_points(int n_type);

string chinese_s(mixed arg)
{
      if (! stringp(arg))return "��";
      if (arg == "cold")return HIW "��";
      if (arg == "fire")return HIR "��";
      if (arg == "magic")return HIY "ħ";
      if (arg == "lighting")return HIM "��";
}


// ����������ID - ͨ���ļ����������ж�
string item_owner()
{
        string owner;
        if (sscanf(base_name(this_object()), ITEM_DIR "%*s/%s-%*s", owner))
                return owner;

        return 0;
}

// �жϸ������Ƿ񱻵�ǰĳ��������
int is_not_belong_me(object me)
{
        string user;

  user = query("user");
        if (! user || ! sscanf(user, "%*s(" + me->query("id") + ")"))
                return 1;

        return 0;
}

// ����װ���ĵȼ�
int weapon_level()
{
        mapping o;
        string *ks;
        int lvl;
        int i;

        lvl = 0;
        o = query("owner");
        if (mapp(o))
        {
                ks = keys(o);
                for (i = 0; i < sizeof(ks); i++)
                        lvl += o[ks[i]];
        }

        lvl /= 100;
        if (lvl > MAX_LEVEL) lvl = MAX_LEVEL;

        if (lvl == MAX_LEVEL && query("magic/power"))
                // ����ħ������
                lvl = ULTRA_LEVEL;
        return lvl;
}

// ����װ���ĵȼ�
int armor_level()
{
        // More to be added
        return 0;
}

// ����װ���ĳ�����
string weapon_long()
{
        string  n;
        mapping c;
        int type;
        int k;
        int lvl;
        string tessera_name;
        string result;
        int enchase_number;
        mixed enchase_objects;
        string* key_objects;
        int i, enchase_points;

        c = query("combat");
        n = query("unit") + name();
        if (! c)
                return "��" + n + "��Ȼ��û��������Ѫ�����洿����Ͼ��\n";
        k = c["MKS"] + c["PKS"];

        if (c["WPK_GOOD"] < k / 2 &&
            c["WPK_BAD"]  < k / 2)
                type = 0;
        else
        if (c["WPK_GOOD"] > c["WPK_BAD"] * 2)
                type = -1;
        else
                type = 1;

        if (c["MKS"] + c["PKS"] < 10)
                return "��" + n + "�����Ѿ��ù���Ѫ��������������Ѫ�ۡ�\n";

        attack_lvl = weapon_level();
        lvl = sizeof(levels);
        while (--lvl)
                if (attack_lvl >= levels[lvl])
                        break;
        lvl++;

        switch (type)
        {
        case 1:
                if (attack_lvl >= ULTRA_LEVEL)
                        result = HIY "������ȥƽƽ������û�а�����⣬ֻ��"
                                 "���������˸е��ǲ��������ʡ�\n" NOR;
                else
                if (attack_lvl >= MAX_LEVEL)
                        result = HIY "������ȥ���˷����������޳羴��һ��"
                               "�Ȼ������Ȼ���棬�ľߵ����緶������\n"
                               "���£�������·�����ɷ���ѵ�����Ǵ�˵�в�"
                               "����ֵ�����֮" + name() + HIY "��\n" NOR;
                else
                if (attack_lvl >= LEVEL8)
                        result = HIC "һ����ȥ��������������������ڷ��"
                               "���裬�������أ�����֮�����ƺ�Ҫ�ط�\n"
                               "�˼䡣���̲�סҪ��̾һ����������ħ��Ҳ�������١�\n" NOR;
                else
                if (attack_lvl >= LEVEL7)
                        result = HIC "�����渽���Ų�֪�����׻꣬����а��"
                               "��ħ�������£�һ�ɰ�����Ȼ��ɢ������\n"
                               "�̲�ס���˸���ս��\n" NOR;
                else
                if (attack_lvl >= LEVEL6)
                        result = HIR "������ȥ���˾��Ķ��ǣ����������������" + name() + HIR
                               "��������ɷ�ʹ˱������ɾ��˼����塣\n" NOR;
                else
                if (attack_lvl >= LEVEL5)
                        result = HIR "����������Ȼ͸��һ��Ѫ�⣬�������������"
                               "����������һʱ����ħ������" + name() + HIR "�µ��λꡣ\n" NOR;
                else
                if (attack_lvl >= LEVEL4)
                        result = HIW "����ǽ��������������֮һ��" + name() + HIW
                               "�����׼���֮ͽ�������޲��ĳ���ҡ��\n" NOR;
                else
                if (attack_lvl >= LEVEL3)
                        result = HIW "��" + n + HIW "��һ������ɢ�������������������׻겻�١�\n" NOR;
                else
                if (attack_lvl >= LEVEL2)
                        result = RED "��" + n + RED "��Ȼ͸��һ��������"
                               "������ɱ�˲����׶�֮ͽ��\n" NOR;
                else
                if (attack_lvl >= LEVEL1)
                        result = RED "ϸ��֮�£��п���һ˿Ѫ�ۣ��������ɱ�˲���"
                               "����Ѫ�ڴ˰ɣ�\n" NOR;
                else
                        result = CYN "���ó���" + n + CYN "����ɱ�������׶�֮ͽ��\n" NOR;
                break;

        case -1:
                if (attack_lvl >= ULTRA_LEVEL)
                        result = HIR "������ȥƽƽ������û�а�����⣬����"
                                 "��֪Ϊ��ȴ�������˸е���Щ������\n" NOR;
                else
                if (attack_lvl >= MAX_LEVEL)
                        result = HIR "������ȥ���˴��ĵ׷��������⣬��"
                               "��Ȼ�����ƺ�����������ԩ�꣬����ȫȻ\n����" + n + HIR
                               "�����ɱ�����ƣ��ѵ�����Ǵ�˵�вŻ���ֵ�а��֮" + name() + HIR
                               "��\n" NOR;
                else
                if (attack_lvl >= LEVEL8)
                        result = HIC "һ����ȥ���������������ԩ��������"
                               "�����������أ�����֮�������̲�ס����\n"
                               "����ս�������ٿ��ڶ��ۡ�\n" NOR;
                else
                if (attack_lvl >= LEVEL7)
                        result = HIC "�����渽���Ų�֪����ԩ�꣬��������"
                               "�������£�һ��Թ��ֱ�������������̲�\n"
                               "ס���˸���ս��\n" NOR;
                else
                if (attack_lvl >= LEVEL6)
                        result = HIW "������ȥ���˾��Ķ��ǣ����������������" + name() + HIW
                               "����֪����Ӣ�۾ʹ����ޡ�\n" NOR;
                else
                if (attack_lvl >= LEVEL5)
                        result = HIW "����������Ȼ͸��һ��Ѫ�⣬�������������"
                               "����������һʱ�ĸ��ֶ�����" + name() + HIW "�µ��λꡣ\n" NOR;
                else
                if (attack_lvl >= LEVEL4)
                        result = HIG "����ǽ���������������֮һ��" + name() + HIG
                               "��˭������ô��������ʿ�������¡�\n" NOR;
                else
                if (attack_lvl >= LEVEL3)
                        result = HIG "��" + n + HIG "��һ������ɢ�������������������λ겻�١�\n" NOR;
                else
                if (attack_lvl >= LEVEL2)
                        result = RED "��" + n + RED "��Ȼ͸��һ��������������ɱ�˲����ˡ�\n" NOR;
                else
                if (attack_lvl >= LEVEL1)
                        result = RED "ϸ��֮�£��п���һ˿Ѫ�ۣ��������ɱ�˲���"
                               "����Ѫ�ڴ˰ɣ�\n" NOR;
                else
                        result = CYN "���ó���" + n + CYN "����ɱ����������֮ʿ��\n" NOR;
                break;

        default:
                if (attack_lvl >= ULTRA_LEVEL)
                        result = HIC "������ȥƽƽ������û�а�����⣬ֻ��һ��"
                                 "ƽ��֮���ı������ѡ�\n" NOR;
                else
                if (attack_lvl >= MAX_LEVEL)
                        result = HIC "����Ȼ���⣬�ƺ���Ҫ�ڿն�ȥ������"
                               "���磬�������С���������·������\n"
                               "��������֮����ԩ�겻�衢Ⱥа���ף��޲�����" + n + HIC
                               "�Ϲ�����İ������ơ�\n" NOR;
                else
                if (attack_lvl >= LEVEL8)
                        result = HIM "һ����ȥ����������������λ�������"
                               "�����������أ�����֮�������ʱ������\n"
                               "�����ޱȣ���������ס��\n" NOR;
                else
                if (attack_lvl >= LEVEL7)
                        result = HIM "�����渽���Ų�֪�����λ꣬������а"
                               "����ɥ�����£�һ��Թ��������Ȼ������\n"
                               "�����̲�ס���˸���ս��\n" NOR;
                else
                if (attack_lvl >= LEVEL6)
                        result = HIR "������ȥ���˾��Ķ��ǣ����������������" + name() + HIR
                               "��������а���ֶ����Ӵ˽٣������ֻء�\n" NOR;
                else
                if (attack_lvl >= LEVEL5)
                        result = HIR "����������Ȼ͸��һ��Ѫ�⣬�������������"
                               "����������һʱ�ĸ��ֶ�������" + n + HIR "�µ��λꡣ\n" NOR;
                else
                if (attack_lvl >= LEVEL4)
                        result = HIW "����ǽ���������������֮һ��" + name() + HIW
                               "��˭���뵽��ô������������¡�\n" NOR;
                else
                if (attack_lvl >= LEVEL3)
                        result = HIW "��" + n + HIW "��һ��ɱ��ɢ�������������������λ겻�١�\n" NOR;

                else
                if (attack_lvl >= LEVEL2)
                        result = RED "��" + n + RED "��Ȼ͸��һ��ɱ����������ɱ�˲����ˡ�\n" NOR;

                else
                if (attack_lvl >= LEVEL1)
                        result = RED "ϸ��֮�£��п���һ˿Ѫ�ۣ��������ɱ�˲���"
                               "����Ѫ�ڴ˰ɣ�\n" NOR;
                else
                        result = CYN "���ó���" + n + CYN "����ɱ�������ˡ�\n" NOR;
                break;
        }

        if (attack_lvl == ULTRA_LEVEL)
        {
                if (stringp(tessera_name = query("magic/tessera")))
                        result += "��������Ƕ��" + tessera_name + "����˸������Ĺ�â��\n";
                result += HIY + name() + HIY "�ĵȼ���������Ʒ  LV10\n" NOR;
        } else
        if (lvl)
        {
                result += HIY + name() + HIY "�ĵȼ���" + lvl + "/9\n" NOR;

                if (query("magic/imbue_ok"))
                        result += HIM + name() + HIM "�Ѿ���ֵĽ����ˣ���Ҫ"
                                  "��Ƕ�Գ�ַ���������\n" NOR;
                else
                if ((n = query("magic/imbue")) > 0)
                        result += HIM + name() + HIM "�Ѿ��������������" +
                                  chinese_number(n) + "�Σ����ڼ�������Ǳ�ܡ�\n" NOR;
        }

              // ��չ��Ƕ��Ʒ��Ϣ
              enchase_objects = query("enchase");
        enchase_points = 0;
              if (! enchase_objects || ! sizeof(enchase_objects))
        {
      enchase_points = 0;
        }
        else
        {
      key_objects = keys(enchase_objects);
                        enchase_number = sizeof(key_objects);
                        for (i = 0; i < enchase_number; i ++)
        enchase_points += enchase_objects[key_objects[i]]["point"];
              }
              // ��װ
              result += HIC "--------------��װ-------------------\n";
              result += HIC "��װ�ȼ���" + TAOZHUANG_D->taozhuang_name(query("taozhuang")) + "\n" NOR;
              result += "-------------------------------------\n";

              result += HIW "��������� " + query("bless") + "\t" NOR;
              result += HIW "������������" + sprintf("%d", query("bless") * 2 + enchase_points) + "\n" NOR;
              result += HIW "ʥ�������� " + query("bless") + "\t" NOR;
              result += HIW "ħ������ֵ��" + query("magic/power") + "\n" NOR;
              result += HIW "ħ�����ԣ�" + chinese_s(query("magic/type"))  + "\t" NOR;
              result += HIW "�����ں϶ȣ�" + query("magic/blood") + "\n" NOR;
355                   // ��ʾǿ���ȼ� 
356                   if (query("qh_level")) 
357                   { 
358                             result +=  HIY "ǿ���ȼ���" + qianghua_level[sprintf("%d", query("qh_level"))] + "\n" NOR; 
359                             if (query("weapon_prop/" + item_owner()+ "_potlimit")) 
360                             { 
361                                     if (this_object()->query("armor_type") == "hands") 
362                                             weapon_type = "armor_prop"; 
363                                     else 
364                                             weapon_type = "weapon_prop"; 
365                                     result += sprintf(HIY "%-10s%-12s%-10s%-10s\n" NOR,  
366                                                       "Ǳ�����ޣ�",  
367                                                       sprintf("+%d", query(weapon_type + "/" + item_owner()+ "_potlimit")) + 
368                                                        "%", 
369                                                       "��չ�ӳɣ�",  
370                                                       sprintf("+%d", 0) + "%"); 
371                             } 
372                   } 
37
        result += HIG "\n---------------��Ƕ��չ--------------\n" NOR;
        result += HIW "��Ƕ��ʹ�ã�  " + sprintf("%d", 1 + enchase_number) + "/" +
                        sprintf("%d", 1 + query("enchase_all")) + "\n";
              result += HIY "---------------��Ƕ����--------------\n" NOR;
              result += sprintf(HIW "%-16s%-20s%-16s\n\n" NOR,"����", "ID", "���");
        if (! stringp(tessera_name))
       tessera_name = HIR "ʮ������������" NOR;
        result += sprintf(NOR + WHT"%-16s%-20s%-16s\n" NOR, filter_color(tessera_name), "----", "----");
        for (i = 0; i < enchase_number; i ++)
      result = result + sprintf(NOR + WHT "%-16s%-20s%-16d\n" NOR,
                                          enchase_objects[key_objects[i]]["name"],
                                          key_objects[i],
                                          enchase_objects[key_objects[i]]["cur_firm"]);
              result += "-------------------------------------\n";
388                   // �������װ��ǿ��Ч���ɹ��ʼӳ�����ʾ 
389                   if (this_object()->query("suc_points_add")) 
390                             result += HIG "Ŀǰ��װ��ǿ��ʱ����" + HIY +  
391                                       sprintf("%d", this_object()->query("suc_points_add")) +  
392                                       HIG "%�ĳɹ��ʣ���һ����Ч����\n" NOR; 
393                   // �������װ��ǿ��Ч��ʧ�ܺ󲻵�������ʾ 
394                    if (this_object()->query("no_reduce_level")) 
395                             result += HIR "Ŀǰ��װ��ǿ��ʱʧ�ܺ󲻻���ʧǿ���ȼ�����һ����Ч����\n" NOR; 

        return result;
}

string armor_long()
{

        mapping enchase_objects;
        int enchase_points, enchase_number, i;
        string* key_objects;
        string result;

        // ��չ��Ƕ��Ʒ��Ϣ
              enchase_objects = query("enchase");
        enchase_points = 0;
              if (! enchase_objects || ! sizeof(enchase_objects))
        {
      enchase_points = 0;
        }
        else
        {
      key_objects = keys(enchase_objects);
                        enchase_number = sizeof(key_objects);
                        for (i = 0; i < enchase_number; i ++)
        enchase_points += enchase_objects[key_objects[i]]["point"];
              }
              // ��װ
              result = "";
              result += HIC "--------------��װ-------------------\n";
              result += HIC "��װ�ȼ���" + TAOZHUANG_D->taozhuang_name(query("taozhuang")) + "\n" NOR;
              result += "-------------------------------------\n";
              result += HIW "��������� " + query("bless") + "\t" NOR;
              result += HIW "������������" + sprintf("%d", query("bless") * 10 + enchase_points) + "\n" NOR;
              result += HIW "ʥ�������� " + query("bless") + "\n" NOR;
430                   // ��ʾǿ���ȼ� 
431                   if (query("qh_level")) 
432                   { 
433                             result += HIY "ǿ���ȼ���" + qianghua_level[sprintf("%d", query("qh_level"))] + "\n" NOR; 
434                             if (query("armor_prop/qh_exp")) 
435                             { 
436                                     result += sprintf(HIY "%-10s%-12s%-10s%-10s\n" NOR,  
437                                                       "��Ϊ�ӳɣ�", sprintf("%d", query("armor_prop/qh_exp")) + "%", 
438                                                       "Ǳ�ܼӳɣ�", sprintf("%d", query("armor_prop/qh_pot")) + "%"); 
439                                     result += sprintf(HIY "%-10s%-12s%-10s%-10s\n" NOR,  
440                                                       "���ӳɣ�", sprintf("%d", query("armor_prop/qh_mar")) + "%", 
441                                                       "��չ�ӳɣ�", sprintf("%d", query("armor_prop/qh_nono")) + "%");                              
442                             } 
443                             if (query("armor_prop/" + item_owner()+ "_potlimit")) 
444                             { 
445                                     result += sprintf(HIY "%-10s%-12s%-10s%-10s\n" NOR,  
446                                                       "Ǳ�����ޣ�",  
447                                                       sprintf("+%d", query("armor_prop/" + item_owner()+ "_potlimit")) + 
448                                                        "%", 
449                                                       "��չ�ӳɣ�",  
450                                                       sprintf("+%d", 0) + "%"); 
451                             } 
452                   } 

        result += HIG "\n---------------��Ƕ��չ--------------\n" NOR;
        result += HIW "��Ƕ��ʹ�ã�  " + sprintf("%d", enchase_number) + "/" +
                        sprintf("%d", query("enchase_all")) + "\n";
              result += HIY "---------------��Ƕ����--------------\n" NOR;
              result += sprintf(HIW "%-16s%-20s%-16s\n\n" NOR,"����", "ID", "���");

        for (i = 0; i < enchase_number; i ++)
      result = result + sprintf(NOR + WHT "%-16s%-20s%-16d\n" NOR,
                                          enchase_objects[key_objects[i]]["name"],
                                          key_objects[i],
                                          enchase_objects[key_objects[i]]["cur_firm"]);
              result += "-------------------------------------\n";

    if (this_object()->query("enchase_all") >= 8)
    {
      log_file("srb_bug", base_name(this_object()) + "\n");
    }
466                   // �������װ��ǿ��Ч���ɹ��ʼӳ�����ʾ 
467                   if (this_object()->query("suc_points_add")) 
468                             result += HIG "Ŀǰ��װ��ǿ��ʱ����" + HIY +  
469                                       sprintf("%d", this_object()->query("suc_points_add")) +  
470                                       HIG "%�ĳɹ��ʣ���һ����Ч����\n" NOR; 
471                   // �������װ��ǿ��Ч��ʧ�ܺ󲻵�������ʾ 
472                    if (this_object()->query("no_reduce_level")) 
473                             result += HIR "Ŀǰ��װ��ǿ��ʱʧ�ܺ󲻻���ʧǿ���ȼ�����һ����Ч����\n" NOR; 
474      
475                     if (this_object()->query("enchase_all") >= 11) 
476                     { 
477                             log_file("srb_bug", base_name(this_object()) + "\n"); 
478                     } 
479      

        return result;
}

// ����ͨ����װ��
int is_weapon()
{
        return stringp(query("skill_type"));
}

// �ǿ�������װ��
int is_unarmed_weapon()
{
        return query("armor_type") == "hands";
}

// ���ߵĳ�����
string item_long()
{
        if (is_weapon() || is_unarmed_weapon())
                return weapon_long();


        return armor_long();
}

// ����װ�����˺�ֵ
int apply_damage()
{
        int d;
        int p;
        int i, enchase_points, enchase_number, flag_9kong;
        mixed enchase_objects;
        string* key_objects;

        attack_lvl = weapon_level();
        p = query("point");
        d = query("bless") * 10; // Ǭ��ʥˮʥ��һ������2�㹥��

        enchase_objects = query("enchase");
  enchase_points = 0;
  flag_9kong = 0;

        if (! enchase_objects || ! sizeof(enchase_objects))
  {
    enchase_points = 0;
  }
  else
  {
    key_objects = keys(enchase_objects);
              enchase_number = sizeof(key_objects);
              for (i = 0; i < enchase_number; i ++)
              {
            enchase_points += enchase_objects[key_objects[i]]["point"];
            // ����оſױ�ʯ--����ʯ�������
            if (enchase_objects[key_objects[i]]["name"] == "����ʯ")flag_9kong = 1;
            }
        }

  // ��Ƕ��ʯ����ʯ�������50%������
  if (flag_9kong)enchase_points = enchase_points + enchase_points / 2;

  if (this_object()->query("enchase_all") >= 11)
  {
    log_file("srb_bug", base_name(this_object()) + "\n");
  }
546      
547             // ���������ǿ�������Ƕ��Ʒ�������˺��ӳ� 
548             // ǿ���ȼ�1-10����ÿ������x% 
549             enchase_points = ITEM_D->qianghua_enchase_points("weapon", enchase_points, query("qh_level")); 
550              
551             // ����Ǳ�ܼӳ� 
552             if (query("qh_level")) 
553             { 
554                     this_object()->set("weapon_prop/" + item_owner()+ "_potlimit",  
555                                                enchase_number * query("qh_level") / 2); 
556                     this_object()->set("armor_prop/" + item_owner()+ "_potlimit",  
557                                                enchase_number * query("qh_level") / 2);                                        
558             } 
559              


        return d + p + enchase_points * 2;
}

// ����װ������Чֵ
int apply_armor()
{
        int d;
        int p;
        int i, enchase_points, enchase_number;
        mixed enchase_objects;
        string* key_objects;

        defense_lvl = armor_level();
        p = query("point");
        d = query("bless") * 10;// Ǭ��ʥˮʥ��һ������2�����

        enchase_objects = query("enchase");
  enchase_points = 0;
        if (! enchase_objects || ! sizeof(enchase_objects))
  {
    enchase_points = 0;
  }
  else
  {
    key_objects = keys(enchase_objects);
                enchase_number = sizeof(key_objects);
                for (i = 0; i < enchase_number; i ++)
                {
      enchase_points += enchase_objects[key_objects[i]]["point"];
    }
        }
  if (this_object()->query("enchase_all") > 11)
  {
    log_file("srb_bug", base_name(this_object()) + "\n");
  }
  // 10����Ƕluhua zhijing ����˺�40
597             // ���绤��ǿ���������˺� 
598             if (this_object()->query("armor_type") == "wrists"|| this_object()->query("armor_type") == "surcoat") 
599             { 
600                     this_object()->set("armor_prop/damage", 0); 
601                     if (enchase_number > 0) 
602                     { 
603                              
604                             for (i = 0; i < enchase_number; i ++ ) 
605                             { 
606                                     // �Ƿ���Ƕ10�ױ�ʯ 
607                                     if (enchase_objects[key_objects[i]]["spe_data"]["luhua-zhijing"]) 
608                                     { 
609                                             // LHZJ����+4000���ټ����ǿ�����Ч�� 
610                                             this_object()->set("armor_prop/damage", 4000); 
611                                     } 
612                             } 
613                             // ���������ǿ���˺� 
614                             if (this_object()->query("armor_type") == "surcoat") 
615                             { 
616                                     this_object()->add("armor_prop/damage", 
617                                     ITEM_D->qianghua_enchase_points("surcoat", enchase_number, query("qh_level"))); 
618                                      
619                                     // �����Ǳ�����޼ӳ� ��ʽ����Ƕ��*ǿ���ȼ�/2% 
620                                     if (query("qh_level")) 
621                                     { 
622                                             // ��������ֵ��Ҳ������ӵ������Ч 
623                                             this_object()->set("armor_prop/" + item_owner()+ "_potlimit",  
624                                                                 enchase_number * query("qh_level") / 2); 
625                                     } 
626                                      
627                             } 
628                             // ���㻤����˺� 
629                             if (this_object()->query("armor_type") == "wrists") 
630                             { 
631                                     this_object()->add("armor_prop/damage", 
632                                     ITEM_D->qianghua_enchase_points("wrists", enchase_number, query("qh_level"))); 
633      
634                                     /*�������Ϊ��Ǳ�ܺ����ļӳ� 
635                                       -- ��Ϊ�ӳɣ�ÿ��ǿ���ȱ�����10%����Ϊ�ӳɣ� 10��ǿ���� 
636                                      ����100%��Ϊ�ӳɡ� 
637                                     -- Ǳ�ܼӳɣ�ǰ5��ǿ��ÿ������4%��Ǳ�ܼӳɣ�6��10��ǿ�� 
638                                      ÿ������16%��Ǳ�ܼӳɡ� 
639                                      10��ǿ��������100%��Ǳ�ܼӳɡ� 
640                                     -- ���ӳɣ�ǰ5��ǿ��ÿ������2%��Ǳ�ܼӳɣ�6��10��ǿ�� 
641                                     ÿ������8%��Ǳ�ܼӳɡ�10��ǿ��������50%��Ǳ�ܼӳɡ� 
642                                     */ 
643                                     if (query("qh_level")) 
644                                     { 
645                                             this_object()->set("armor_prop/qh_exp", query("qh_level")*3); 
646                                             if (query("qh_level") <= 5) 
647                                             { 
648                                                     this_object()->set("armor_prop/qh_pot", query("qh_level")*2); 
649                                                     this_object()->set("armor_prop/qh_mar", query("qh_level")*2); 
650                                                     // ����ӵ���� 
651                                                     this_object()->set("armor_prop/" + item_owner()+ "_wrists", 1); 
652                                             } 
653                                             else 
654                                             { 
655                                                     this_object()->set("armor_prop/qh_pot",  
656                                                       5 * 2 + (query("qh_level") - 5)*4); 
657                                                     this_object()->set("armor_prop/qh_mar",  
658                                                       5 * 2 + (query("qh_level") - 5)*3); 
659                                                     // ����ӵ���� 
660                                                     this_object()->set("armor_prop/" + item_owner()+ "_wrists", 1); 
661                                             } 
662                                             /* ÿ����Ƕ�������� 
663                                             ÿ����Ƕ��ɶ�����������Ϊ�ӳ�3% 
664                                             ÿ����Ƕ��ɶ���������2%��Ǳ�ܼӳ� 
665                                             ÿ����Ƕ��ɶ�������1%�����ӳ� 
666                                             */ 
667                                             this_object()->add("armor_prop/qh_exp", enchase_number*3); 
668                                             this_object()->add("armor_prop/qh_pot", enchase_number*2); 
669                                             this_object()->add("armor_prop/qh_mar", enchase_number*1); 
670                                              
671                                     } 
672                             } 
673                     } 
674             } 


  /*
  if (find_player("rcwiz") && query("user") == "�������ġ�(rcwiz)" )
    tell_object(find_player("rcwiz"), HIR "\narmor_type = " + query("armor_type") + "\n" +
                                          "" NOR );
  */
  if (1 || query("armor_type") == "head") // ���ݲ�������ط�ȡ����armor_type
  {
    if (sizeof(key_objects))
    {
      this_object()->set("armor_prop/add_yanjiu", 0);
      this_object()->set("armor_prop/add_jiqu", 0);

      for (i = 0; i < sizeof(key_objects); i ++ )
      {
        // ����о�Ч��
        if (enchase_objects[key_objects[i]]["spe_data"]["add_yanjiu"])
          this_object()->add("armor_prop/add_yanjiu",
                             enchase_objects[key_objects[i]]["spe_data"]["add_yanjiu"]);
        // ��߼�ȡЧ��
        if (enchase_objects[key_objects[i]]["spe_data"]["add_jiqu"])
          this_object()->add("armor_prop/add_jiqu",
                             enchase_objects[key_objects[i]]["spe_data"]["add_jiqu"]);
      }
    }
  }

        return (d + p + enchase_points * 2) * 6 / 5;
}

// n_type = 0 : ��Ե   n_type = 1 �� ����
int f_enchase_points(int n_type)
{
        int i, enchase_points, enchase_number;
        mixed enchase_objects;
        string* key_objects;

        enchase_objects = query("enchase");
  enchase_points = 0;

        if (! enchase_objects || ! sizeof(enchase_objects))
  {
    enchase_points = 0;
  }
  else
  {
    key_objects = keys(enchase_objects);
                enchase_number = sizeof(key_objects);
                for (i = 0; i < enchase_number; i ++)
                {
                  if (n_type)
                    enchase_points += enchase_objects[key_objects[i]]["qy"];
                  else
                    enchase_points += enchase_objects[key_objects[i]]["fy"];
    }
        }

        return enchase_points;

}

// ���б������ݵĽӿں���
mixed save_dbase_data()
{
        mapping data;
        object  user;

        data = ([ "combat" : query("combat"),
                  "owner"  : query("owner"),
                  "magic"  : query("magic"),
                  "consistence" : query("consistence"),
                  "bless"       : query("bless"),
                  "stable"      : query("stable"),
      "enchase"     : query("enchase"),
                  "enchase_all" : query("enchase_all"),
                  "enchase_all_last" : query("enchase_all_last"),// �ǻ�ԱʧЧ��ʱ��׵�����
                  //"new_long"         : query("new_long"),             // ���Ը���long����
                  //"new_wear_msg"     : query("new_wear_msg"),         // ���Ը���װ��ʱ������
                  //"new_remove_msg"   : query("new_remove_msg"),       // ���Ը���ȡ��װ��ʱ������
                  "taozhuang"   : query("taozhuang"), // ��װ�ȼ�
754                       "qh_level"    : query("qh_level"), // ǿ���ȼ� 
755                       "suc_points_add" : query("suc_points_add"), // ǿ���ɹ������� 
756                       "no_reduce_level": query("no_reduce_level"), // ǿ��ʧ�ܲ����ȼ�                 

                  ]);

        if (! (user = environment()))
                data += ([ "user" : query("user") ]);
        else
        if (playerp(user))
                data += ([ "user" : user->name(1) + "(" + user->query("id") + ")" ]);

        return data;
}

// ���ܴ������ݵĽӿں���
int receive_dbase_data(mixed data)
{

        if (! mapp(data))
                return 0;
/*
  // ���������������������long,wear_msg, remove_msg������
        if (stringp(data["new_long"]))
                set("new_long", data["new_long"]);
        if (stringp(data["new_wear_msg"]))
                set("new_wear_msg", data["new_wear_msg"]);
        if (stringp(data["new_remove_msg"]))
                set("new_remove_msg", data["new_remove_msg"]);
*/
        if (mapp(data["combat"]))
                set("combat", data["combat"]);

        if (mapp(data["owner"]))
                set("owner", data["owner"]);

        if (mapp(data["magic"]))
                set("magic", data["magic"]);

        if (stringp(data["user"]))
                set("user", data["user"]);

        if (! undefinedp(data["consistence"]))
                set("consistence", data["consistence"]);

        if (intp(data["bless"]))
                set("bless", data["bless"]);

        // ��װ
        if (intp(data["taozhuang"]))
                set("taozhuang", data["taozhuang"]);
805             // ǿ���ȼ� 
806             if (intp(data["qh_level"])) 
807                     set("qh_level", data["qh_level"]);       
808             // ǿ�����ӳɹ��� 
809             if (intp(data["suc_points_add"])) 
810                     set("suc_points_add", data["suc_points_add"]); 
811             // ǿ��ʧ�ܲ����ȼ� 
812             if (intp(data["no_reduce_level"])) 
813                     set("no_reduce_level", data["no_reduce_level"]); 
814      

        if (intp(data["stable"]))
                set("stable", data["stable"]);

        if (mapp(data["enchase"]))
                set("enchase", data["enchase"]);

        if (intp(data["enchase_all"]))
    set("enchase_all", data["enchase_all"]);

        if (intp(data["enchase_all_last"]))
    set("enchase_all_last", data["enchase_all_last"]);
}

// ��ȡ���̵�����
int restore()
{
        int r;

        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

        r = ::restore();
        set("no_sell", 1);
        set("stable", query("stable"));
        set("bless", query("bless"));
  set("enchaes", query("enchase"));
  set("enchase_all", query("enchase_all"));
  set("taozhuang", query("taozhuang")); // ��װ
843             set("qh_level", query("qh_level")); // ǿ���ȼ� 
844             set("suc_points_add", query("suc_points_add")); // ǿ���ɹ������� 
845             set("no_reduce_level", query("no_reduce_level")); // ǿ�������ȼ�        

/*
  // ������long����
  if (stringp(query("new_long")) && sizeof(query("new_long")) > 0)
  {
    set("long", query("new_long") + "\n");
  }
  else
  {
    set("long", query("long"));
  }
  // �����µ�wear_msg����
  // Ҫ�Ա��������жϣ�query(skill_type)Ϊ��������wield_msg
  //                   query(armor_type)Ϊ���ߣ���wear_msg
  if (stringp(query("new_wear_msg")) && sizeof(query("new_wear_msg")) > 0)
  {
    if (stringp(query("skill_type")))
    {
      set("wield_msg", query("new_wear_msg") + "\n");
    }
    else
    {
      set("wear_msg", query("new_wear_msg") + "\n");
    }
  }
  else
  {
    if (query("skill_type"))
    {
      set("wield_msg", query("wield_msg") + "\n");
    }
    else
    {
      set("wear_msg", query("wear_msg") + "\n");
    }

  }

  // �����µ�remove_msg����
  // Ҫ�Ա��������жϣ�query(skill_type)Ϊ��������wield_msg
  //                   query(armor_type)Ϊ���ߣ���wear_msg
  if (stringp(query("new_remove_msg")) && sizeof(query("new_remove_msg")) > 0)
  {
    if (query("skill_type"))
    {
      set("unwield_msg", query("new_remove_msg") + "\n");
    }
    else
    {
      set("remove_msg", query("new_remove_msg") + "\n");
    }

  }
  else
  {
    if (query("skill_type"))
    {
      set("unwield_msg", query("unwield_msg") + "\n");
    }
    else
    {
      set("remove_msg", query("remove_msg") + "\n");
    }
  }

*/
  if (query("enchase_all") >= 11)
  {
    log_file("srb_bug", base_name(this_object()) + "\n");
  }

  if (! MEMBER_D->is_valib_member(item_owner()) && query("enchase_all") > 4 )
  {
    set("enchase_all_last", query("enchase_all"));
    set("enchase_all", 4);
  }
  if (MEMBER_D->is_valib_member(item_owner()))
  {
    if (query("enchase_all_last") > query("enchase_all"))
      set("enchase_all", query("enchase_all_last"));
  }

        return r;
}

// ��������
int save()
{
  int res;

        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

  return ::save();
}

// 9/10��������������
mixed weapon_hit_ob(object me, object victim, int damage_bonus)
{
        int ap;
        int dp;
        int damage;

        if (attack_lvl < MAX_LEVEL ||
      query("owner/" + me->query("id")) < MAX_LEVEL * 80)
                return;

        if (attack_lvl >= ULTRA_LEVEL &&
            mapp(query("magic")))
        {
                return ITEM_D->weapon10lv_hit_ob(me, victim, this_object(), damage_bonus);
        }

        return ITEM_D->weapon_hit_ob(me, victim, this_object(), damage_bonus);
}

// ���µĺ�����Ϊִ�е�Ƶ�Ȳ����ߣ����Ҿ��и߶��ظ������ʣ�
// ���Զ�����ITEM_D�е�ִ�г���

// ɱ�����Ժ�Ľ���
void killer_reward(object me, object victim)
{
  ITEM_D->killer_reward(me, victim, this_object());
}

// ������Ʒ
int receive_summon(object me)
{
  return ITEM_D->receive_summon(me, this_object());
}

// ������Ʒ
int hide_anywhere(object me)
{
        return ITEM_D->hide_anywhere(me, this_object());
}

// ׷Ѱ��Ʒ
int receive_miss(object me)
{
        if (! is_weapon() && ! is_unarmed_weapon())
        {
                write("���޷�׷Ѱ" + name() + "��\n");
                return 0;
        }

        if (attack_lvl < ULTRA_LEVEL)
        {
                write(name() + "��δͨ�飬����������ĸ�Ӧ��\n");
                return 0;
        }

  return ITEM_D->receive_miss(me, this_object());
}

// ���ڵ���
int do_stab(object me)
{
        return ITEM_D->do_stab(me, this_object());
}

// ��������
int do_touch(object me)
{
        if (attack_lvl != ULTRA_LEVEL)
                return notify_fail("�����˰��죬����ûʲô��Ӧ��\n");

        return ITEM_D->do_touch(me, this_object());
}

// ʥ��
int do_san(object me)
{
        if ((is_weapon() || is_unarmed_weapon()) &&
            attack_lvl < MAX_LEVEL)
                return notify_fail("��������ȼ��������޷�ʥ����\n");

        return ITEM_D->do_san(me, this_object());
}

// ��͸��Ʒ
int do_imbue(object me, object imbue)
{
        return ITEM_D->do_imbue(me, this_object(), imbue);
}

// ��Ƕ��Ʒ
int do_enchase(object me, object tessera)
{
        return ITEM_D->do_enchase(me, this_object(), tessera);
}

int query_autoload() { return (query("equipped") ? query("equipped") : "kept"); }

void autoload(string parameter)
{
    if (this_object()->query("enchase_all") >= 10)
    {
      log_file("srb_bug", base_name(this_object()) + "\n");
    }

        switch (parameter)
        {
        case "worn":
                this_object()->wear();
                break;

        case "wielded":
                this_object()->wield();
                break;
        }
}
