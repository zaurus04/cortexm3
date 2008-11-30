/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: jsp_parser.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/jsp/jsp_parser.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $

#include <stdarg.h>

#include "jsp/jsp_defs.h"
#include "base/parser.h"
#include "base/mpstrstream.h"
#include "jsp/jsp_common.h"

#include <set>
#include <map>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace ToppersJsp;
using namespace std;

class CoreParser : public ParserComponent
{
protected:
    virtual void parseOption(Directory &);
            void outputContainer(Directory & container) throw();
            void assignID(Directory & container) throw();

public:
    CoreParser(void);
    virtual bool parse(Parser & p, Directory & container);
} instance_of_Parser;

CoreParser::CoreParser(void)
{
    setBanner("=== TOPPERS/JSP Kernel Configurator ver.9.4 (for JSP rel 1.4) ===");
}

void CoreParser::parseOption(Directory & container)
{
    ParserComponent::parseOption(container);

    if(findOption("h","help"))
    {
        cerr << Message(
            "  -obj, --dump-object=filename : Dump the object tree into the file specified\n"
            "  -ao, --assign-order=order : Specify the order of automatic ID assignment\n"
            "    You can use three terms below as ordering rule.\n"
            "     alphabetic (in alphabetic order)\n"
            "     fcfs       (in arrival order [as default])\n"
            "     reverse    (reverse the order)\n"
            "  -var, --variable-id : Prepare ID-variable for storing its identifier number\n",
            "  -obj, --dump-object=�t�@�C���� : �w�肵���t�@�C���ɃI�u�W�F�N�g�����o�͂��܂�\n"
            "  -ao, --assign-order=���� : ����ID�����̊����������w�肵�܂�\n"
            "    ���������͎���3�̑g�����Ŏw�肵�܂�.\n"
            "     alphabetic (ABC��), fcfs (�錾�� [�f�t�H���g]), reverse (�t��)\n"
            "  -var, --variable-id : ID�ԍ����i�[����ϐ���p�ӂ��܂�");
        return;
    }

    checkOption("D","dump");
    checkOption("cpu","cpu");
    checkOption("system","system");
    checkOption("var","variable-id");
}

namespace {
	int displayHandler(Directory & container, const char * category, const char * format)
	{
	    Directory * node  = 0;
	    Directory * scope = 0;

	    node = container.findChild(OBJECTTREE,category,NULL);
	    if(node == 0 || node->size() == 0)
		return 0;

	    VerboseMessage("Handler assignment list [%]\n","�n���h�����t�\ [%]\n") << category;

	    scope = node->getFirstChild();
	    while(scope != 0)
	    {
		VerboseMessage::getStream() << scope->format(format);
		scope = scope->getNext();
	    }

	    return node->size();
	}

	//�}�N�������ꂽtoupper���֐������� (STL-algorithm�p)
	int toupper_function(int c)
	{ return toupper(c); }
}
/*
 *  outputContainer - �f�o�b�O�� or �_���v�w�莞�ɃI�u�W�F�N�g��������̃t�@�C���`���ŏo�͂���
 */
void CoreParser::outputContainer(Directory & container) throw()
{
    try {

        if(findOption("D","dump") || findOption("debug","debug")) {
            fstream file("container.txt", ios::out);
            container.drawTree(&file);
            file.close();
        }

        if(findOption("Dx","dump-xml") || findOption("debug","debug")) {
            fstream file("container.xml", ios::out);
            container.drawTree_byXML(&file);
            file.close();
        }
    }
    catch (...) {
    }
}

/*
 *  assignID - �I�u�W�F�N�g�ɑ΂���ID������t����
 *             ��荞�񂾃I�u�W�F�N�g�������[�U�ɒ񎦂���
 */
void CoreParser::assignID(Directory & container) throw()
{
    multimap<int, const char *> sorter;
    multimap<int, const char *>::iterator scope;
    enum Common::tagAssignmentOrder order = Common::FCFS;

    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" TASK].size(), TASK));
    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" SEMAPHORE].size(), SEMAPHORE));
    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" EVENTFLAG].size(), EVENTFLAG));
    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" DATAQUEUE].size(), DATAQUEUE));
    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" MAILBOX].size(), MAILBOX));
    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" FIXEDSIZEMEMORYPOOL].size(), FIXEDSIZEMEMORYPOOL));
    sorter.insert(pair<int, const char *>(container[OBJECTTREE "/" CYCLICHANDLER].size(), CYCLICHANDLER));

    order = Common::parseOrder(getOption("ao", "assign-order"));
    scope = sorter.begin();
    while(scope != sorter.end())
    {
        if( (*scope).first != 0 )
            Common::assignID(container, (*scope).second, OBJECTTREE, order);
        ++ scope;
    }

    displayHandler(container, INTERRUPTHANDLER, "  $@ : $(inthdr)\n");
    displayHandler(container, EXCEPTIONHANDLER, "  $@ : $(exchdr)\n");
    displayHandler(container, INITIALIZER, "  $@ : $(inirtn)($(exinf))\n");
    displayHandler(container, TERMINATOR, "  $@ : $(terrtn)($(exinf))\n");
}


bool CoreParser::parse(Parser & p, Directory & container)
{
    Token token;
    string work;
    bool isParseErrorOccured;

    if(findOption("cpu","cpu", &work))
        container["/cpu"] = work;
    
    try{
        isParseErrorOccured = false;
        do {
            p.getToken(token);
            if(token == Token::IDENTIFIER)
            {
                    /* �G���[���N���Ă��ɗ͑��������̂ŁA
                        �N�������Ƃ����o���Ă����Ăǂ�ǂ񑱂��� */
                try 
                {   this->parseStaticAPI(p, container, token);  }
                catch(...)
                {   isParseErrorOccured = true;                 }

            }
        }while(token != Token::EOS);

        p.setLogBuffer(NULL);

        if(isParseErrorOccured)
            ExceptionMessage(ExceptionMessage::FATAL,"The configuration process was aborted due to occurence of parse error","�\����͂Ɏ��s�������ߏ����𒆒f���܂�").throwException();

        if(container[OBJECTTREE "/" TASK].size() == 0)
            ExceptionMessage("Kernel requires one or more task objects.","�^�X�N�I�u�W�F�N�g������܂���").throwException();

            /* ID���t & �I�u�W�F�N�g���\�� */
        assignID(container);

            /* �I�u�W�F�N�g�����t�@�C���ɏo�� */
        outputContainer(container);

        return true;
    }
    catch(Exception &)
    {
            /* ��O�𓊂��Ȃ����O�� ���݂̃I�u�W�F�N�g�����i�[���� */
        outputContainer(container);
        throw;
    }
}

/* ======================================================================== */

DECLARE_DIRECTIVE(assigner,"assign_id")
{
    Token name;
    Token value;

    p.getToken(name, Token::IDENTIFIER);
    p.getToken(value, Token::INTEGER);

    if(value.value <= 0)
        ExceptionMessage("Cannot assign an ID number less or equal to 0.","0�ȉ���ID�ԍ���ݒ肷�邱�Ƃ͂ł��܂���").throwException();

    *container.openChild("/","identifier",name.c_str(),NULL) = value.value;
}

DECLARE_DIRECTIVE(parameter,"parameter")
{
    Token token;
    string key;
    string::size_type i,j;

    do {
        p.getToken(token);
        if(!(token == Token::STRINGLITERAL))
            ExceptionMessage("parameter pragma requires additional parameter put in '\"...\"'","parameter�v���O�}�ɂ�\"...\"�Ŋ���ꂽ�ǉ��p�����[�^���K�v�ł�").throwException();

        token.chopLiteral();

        if(token[0] == '-')
        {
            i = token.find_first_of('=');
            j = token.find_first_not_of('-');
            if(i == j || j == string::npos)
                ExceptionMessage(ExceptionMessage::FATAL,"Wrong option [%]","�s���ȃI�v�V���� [%]") << token << throwException;

            if(i != string::npos)
            {
                key = DEFAULT_PARAMETER;
                *container.openChild(string("/Parameter/") + token.substr(1, i-1)) = token.substr(i+1);
            }
            else
            {
                key = token.substr(1);
                *container.openChild(string("/Parameter/") + key) = string("");
            }
        }else
            *container.openChild(string("/Parameter/") + key) = token;

        p.getToken(token);
    } while(token.compare(",") == 0);

    p.putBack(token);
}


/* ======================================================================== */
class ConfigurationFileGenerator : public Component
{
protected:
    bool backward_compatible;
    bool libstyle_include;
    bool restrict_zero;
    bool def_prototype;

    enum tagDefinition { HEADER=1, TNUM=2, BUFFER=4, DEFINITION=8, CONTROLBLOCK=16, SHORT_ID=32, TNUMNO=64, INIT=128, PROTOTYPE=256, INITLIST=512 };
    void createObjectDefinition(MultipartStream *, Directory &, int, ...);

    virtual void parseOption(Directory &);
    virtual void body(Directory &);
    virtual void onFatalExit(Directory &);

public:
    ConfigurationFileGenerator(void) : Component(CODEGENERATOR) {};
} instance_of_Configurator;



namespace {

        //�t�@�C�����̎擾
    string get_filename(string category, string _default) throw(Exception)
    {
        string result(_default);
        OptionParameter::OptionItem item = getOptionParameter()[category];

        if(item.isValid()) {
            if(item.countParameter() == 1)
                result = item[0];
            else
                ExceptionMessage("-% should have just ONE filename.","-%�I�v�V�����Ɏw��ł���t�@�C����1�̂�") << category << throwException;
        }

        if(result.empty())
            ExceptionMessage("-% has illegal file name.","-%�I�v�V�����ɓn���ꂽ�t�@�C�����͕s��") << category << throwException;
        
        return result;
    }

        // �J�[�l���\���t�@�C���̐���
    KernelCfg * createKernelCfg(void)
    {
        KernelCfg * cfg;

        cfg = KernelCfg::createInstance(get_filename("kernel_cfg","kernel_cfg.c"));
        cfg->disableOutput();       //��������������܂ŏo�͂����Ȃ�

            //��{�I�ȃI�u�W�F�N�g�̊i�[�ꏊ�͂����Ŏw�肵�Ă���
        cfg->createPart("header")
            .createPart("include")
            .createPart(IDENTIFIER_VARIABLE)
            .createPart(TASK)
            .createPart(SEMAPHORE)
            .createPart(EVENTFLAG)
            .createPart(DATAQUEUE)
            .createPart(MAILBOX)
            .createPart(FIXEDSIZEMEMORYPOOL)
            .createPart(CYCLICHANDLER)
            .createPart(INTERRUPTHANDLER)
            .createPart(EXCEPTIONHANDLER)
            .createPart(INITIALIZER)
            .createPart(OBJECT_INITIALIZER)
            .createPart("others");

            //�J�[�l���\���t�@�C�������C�x���g�̎��s
        KernelCfg::CreationEvent ev;
        ev.file = cfg;
        Event<KernelCfg::CreationEvent>::raise(ev);

            //�G���[�`�F�b�N
        if(ev.file == 0)
            ExceptionMessage("Internal error : kernel_cfg event handler eliminates the instance.","�����G���[ : kernel_cfg�̃n���h�����C���X�^���X���폜����") << throwException;
        if(RuntimeObjectTable::getInstance(typeid(KernelCfg)) != ev.file)
            ExceptionMessage("Internal error : kernel_cfg event handler creates the illegal instance.","�����G���[ : kernel_cfg�̃n���h�����s���ȃC���X�^���X�𐶐�����") << throwException;

        return ev.file; //cfg�ł̓_��
    }

        //�t�@�C��������Փˉ��p�̖��O�𐶐�����
    string convert_filename_to_definition(string filename)
    {
        string result;
        string::iterator scope;

        scope = filename.begin();
        while(scope != filename.end()) {
            if(isalnum(*scope))
                result += static_cast<char>(toupper(*scope));
            else
                result += '_';
            ++ scope;
        }

        return result;
    }

        //����ID���t���ʃt�@�C���̐���
    KernelID * createKernelID(void)
    {
        KernelID * id = 0;

        id = KernelID::createInstance(get_filename("kernel_id","kernel_id.h"));
        id->disableOutput();

            //��{�I�ȃI�u�W�F�N�g�̊i�[�ꏊ�͂����Ŏw�肵�Ă���
        id-> createPart("__header__")
            .createPart("body")
            .createPart("__footer__");

            //�t�@�C�������C�x���g�̎��s
        KernelID::CreationEvent ev;
        ev.file = id;
        Event<KernelID::CreationEvent>::raise(ev);

            //�G���[�`�F�b�N
        if(ev.file == 0)
            ExceptionMessage("Internal error : kernel_id event handler eliminates the instance.","�����G���[ : kernel_id�̃n���h�����C���X�^���X���폜����") << throwException;
        if(RuntimeObjectTable::getInstance(typeid(KernelID)) != ev.file)
            ExceptionMessage("Internal error : kernel_id event handler creates the illegal instance.","�����G���[ : kernel_id�̃n���h�����s���ȃC���X�^���X�𐶐�����") << throwException;

            //���d�C���N���[�h���p��`�̒ǉ�
        string defname = convert_filename_to_definition(id->getFilename());
        id->movePart("__header__");
        (*id)   // << get_agreement(id->getFilename())      //�����̕t�^
                << "#ifndef " << defname << '\n'        //#ifndef KERNELID_H
                << "#define " << defname << "\n\n";     //#define KERNELID_H
        
        id->movePart("__footer__");
        (*id)   << "\n#endif /* " << defname << " */\n\n";          //#endif /* KERNELID_H */

        return ev.file; //id�ł̓_��
    }

        //�o�^����Ă��镶���̍ő咷�𓾂�
    unsigned int countLongestSymbolName(const std::map<std::string, int> & identifiers) throw()
    {
        unsigned int max_length = 0;
        std::map<std::string, int>::const_iterator scope;

            // �����Ƃ��������O�����V���{����������
        scope = identifiers.begin();
        while(scope != identifiers.end()) {
            if(max_length < scope->first.size())
                max_length = scope->first.size();
            ++ scope;
        }

        return max_length;
    }

        //����ID���t���ʏo�� (����܂łƂ̌݊����[�h)
    void serializeIdentifiers_defineStyle(KernelID * out, std::map<std::string, int> & identifier_pool)
    {
        std::map<std::string, int>::const_iterator scope;
        string::size_type max_length;

        (*out) << "\t/* object identifier deifnition */\n\n";

            // �����Ƃ��������O�����V���{����������
        max_length = countLongestSymbolName(identifier_pool);

        scope = identifier_pool.begin();
        while(scope != identifier_pool.end()) {
            (*out)  << "#define " << scope->first 
                    << string(max_length - scope->first.size() + 4, ' ')    //�l�����낦��
                    << setw(3)
                    << scope->second << '\n';
            ++ scope;
        }
    }

        //����ID���t���ʏo�� (�萔�ϐ��i�[����)
    void serializeIdentifiers_variableStyle(KernelID * id, std::map<std::string, int> & identifier) throw(Exception)
    {
        std::map<std::string, int>::const_iterator scope;
        string::size_type max_length;
        KernelCfg * cfg = getRuntimeObjectInstance(KernelCfg);

            /* kernel_id.h�ɏo�� */

        (*id) << "#ifdef __cplusplus\n"
                 "#define KERNELID_EXPORT extern \"C\"\n"
                 "#else\n"
                 "#define KERNELID_EXPORT extern\n"
                 "#endif\n\n";

            // �����Ƃ��������O�����V���{����������
        max_length = countLongestSymbolName(identifier);

        scope = identifier.begin();
        while(scope != identifier.end()) {
            (*id) << "KERNELID_EXPORT const int "
                  << scope->first
                  << ";\n";

            ++ scope;
        }

        (*id) << "\n#undef KERNELID_EXPORT\n\n";

            /* kernel_cfg.c�ɒ萔��`���o�� */

        cfg->movePart(IDENTIFIER_VARIABLE);
        (*cfg) << "\t/* Identifier storage variables */\n";
        scope = identifier.begin();
        while(scope != identifier.end()) {
            (*cfg) << "const int " 
                  << scope->first
                  << string(max_length - scope->first.size() + 4, ' ')
                  << " = "
                  << scope->second << ";\n";
            ++ scope;
        }
    }

        //����ID���t���ʏo�� (���p���� - (toppers-dev 28))
    void serializeIdentifiers_blendedStyle(KernelID * id, std::map<std::string, int> & identifier) throw(Exception)
    {
        /* kernel_id.h�ւ̏o�͂͏]���Ɠ��� */
        serializeIdentifiers_defineStyle(id, identifier);

            /* kernel_cfg.c�ɒ萔��`���o�� */

        std::map<std::string, int>::const_iterator scope;
        string::size_type max_length;
        KernelCfg * cfg = getRuntimeObjectInstance(KernelCfg);

        max_length = countLongestSymbolName(identifier);

        cfg->movePart(IDENTIFIER_VARIABLE);
        (*cfg) << "\t/* Identifier storage variables */\n";
        scope = identifier.begin();
        while(scope != identifier.end()) {
            (*cfg) << "const int " 
                  << scope->first
                  << "_id"
                  << string(max_length - scope->first.size() + 1, ' ')
                  << " = "
                  << scope->second << ";\n";
            ++ scope;
        }
    }

        //����ID���t���ʂ̏o��
    void serializeIdentifiers(bool varid_style = false) throw(Exception)
    {
        KernelID * out = getRuntimeObjectInstance(KernelID);
        std::map<std::string, int> identifier_pool;

            //���ʎq�v�[���𐶐�
        {
            Directory * scope = Singleton<Directory>::getInstance()->findChild("/identifier")->getFirstChild();
            while(scope != 0)
            {
                identifier_pool[scope->getKey()] = scope->toInteger();
                scope = scope->getNext();
            }
        }

            //���t���ʂ̏o��
        out->movePart("body");
        if(varid_style) {
            serializeIdentifiers_blendedStyle(out, identifier_pool);
//            serializeIdentifiers_variableStyle(out, identifier_pool);
        }
        else {
            serializeIdentifiers_defineStyle(out, identifier_pool);
        }

        out->enableOutput();
    }

    void serializeConfiguration_headerPart(KernelCfg & out) throw(Exception)
    {
        const bool backward_compatible = getOptionParameter()["1.3"].isValid();
        
            //���̕����̏o��
        out.movePart("header");

        out // << get_agreement(out.getFilename())          //�����̓Y�t
            << "/* Configured with ["                   //�R���t�B�M�����[�V�����I�v�V�������o�͂��Ă���
            << getOptionParameter().getCommandLine() 
            << "] */\n\n";

            //1.4�ȍ~��kernel_cfg.h���g�p
        if(!backward_compatible)
            out << "#include " << conv_includefile("kernel_cfg.h") << '\n';

            //kernel_id.h��include (kernel_id�̓_�u���N�H�[�g�ł�����)
        out << "#include \"" << dynamic_cast<KernelID *>(RuntimeObjectTable::getInstance(typeid(KernelID)))->getFilename() <<"\"\n" 
            << '\n';


            //CFG_INT/EXCHDR_ENTRY
            // Q: "<<"����������Ȃ������肷��̂͂Ȃ�? A: 2�s�ڂ���5�s�ڂ܂ł�else�u���b�N�ŏo�͂��Ă�����e�Ƃ܂����������B��������΃R���p�C���ɂ���Ă̓V�������N����Ĉ�ɂȂ邵�A�ǐ��������Ȃ�Ȃ��B
        if(backward_compatible) {
            out << "#if TKERNEL_PRVER >= 0x1040\n"
                << "#error \"This configuration file has no compatibility with"
                << " TOPPERS/JSP rel 1.4 or later version.\"\n"
                   "#elif TKERNEL_PRVER >= 0x1011\n"
                << "#define CFG_INTHDR_ENTRY(inthdr) INTHDR_ENTRY(inthdr)\n"
                   "#define CFG_EXCHDR_ENTRY(exchdr) EXCHDR_ENTRY(exchdr)\n"
                   "#define CFG_INT_ENTRY(inthdr) INT_ENTRY(inthdr)\n"
                   "#define CFG_EXC_ENTRY(exchdr) EXC_ENTRY(exchdr)\n"
                << "#else\n"
                << "#define CFG_INTHDR_ENTRY(inthdr) INTHDR_ENTRY(ENTRY(inthdr), inthdr)\n"
                   "#define CFG_EXCHDR_ENTRY(exchdr) EXCHDR_ENTRY(ENTRY(exchdr), exchdr)\n"
                   "#define CFG_INT_ENTRY(inthdr) ENTRY(inthdr)\n"
                   "#define CFG_EXC_ENTRY(exchdr) ENTRY(exchdr)\n"
                << "#endif\n\n";
        }
        else {
            out << "#if TKERNEL_PRVER >= 0x1040\n"
                << "#define CFG_INTHDR_ENTRY(inthdr) INTHDR_ENTRY(inthdr)\n"
                   "#define CFG_EXCHDR_ENTRY(exchdr) EXCHDR_ENTRY(exchdr)\n"
                   "#define CFG_INT_ENTRY(inthdr) INT_ENTRY(inthdr)\n"
                   "#define CFG_EXC_ENTRY(exchdr) EXC_ENTRY(exchdr)\n"
                << "#else\n"
                << "#error \"This configuration file has no compatibility with"
                << " TOPPERS/JSP rel 1.3 or earlier.\"\n"
                << "#endif\n\n";
        }

            //__EMPTY_LABEL�}�N���̏o��
        if(!getOptionParameter()["z"].isValid()) {
            
            string zeromacro;

            if(getOptionParameter()["ZERO"].isValid())
                zeromacro = getOptionParameter()["ZERO"][0];
            else
                zeromacro.assign("x y[0]");

            out <<  "#ifndef __EMPTY_LABEL\n"
                    "#define __EMPTY_LABEL(x,y) " << zeromacro << "\n"
                    "#endif\n\n";
        }

            /* PRID�̃`�F�b�N */
        out << "#if TKERNEL_PRID != 0x0001u /* TOPPERS/JSP */\n"
               "#error \"You can not use this configuration file without TOPPERS/JSP\"\n"
               "#endif\n\n";
    }
}

void ConfigurationFileGenerator::parseOption(Directory & parameter)
{
    string work;

    if(findOption("h","help"))
    {
        cerr << endl << Message(
            "Kernel configuration file generator\n"
            "  -id, --kernel_id=filename  : Specify the name of ID assignment file\n"
            "  -cfg,--kernel_cfg=filename : Specify the name of kernel configuration file\n"
            "  -il, --include-libstyle    : Use #include <...> style for kernel headers\n"
            "  -oproto, --output-prototype: Output task prototype definitions in kernel_cfg\n"
            "  -z, --nonzero              : Do not output __EMPTY_LABEL macro and related definitions\n"
            "  -1.3  : Generates kernel_cfg.c for TOPPERS/JSP rel 1.3\n",
            "�J�[�l���\���t�@�C���̐���\n"
            "  -id, --kernel_id=�t�@�C����  : ID�����t�@�C���̖��O���w�肵�܂�\n"
            "  -cfg,--kernel_cfg=�t�@�C���� : �J�[�l���\���t�@�C���̖��O���w�肵�܂�\n"
            "  -il, --include-libstyle      : �J�[�l���̃w�b�_�t�@�C����<...>�̌`�ŏo�͂��܂�\n"
            "  -oproto, --output-prototype  : �^�X�N�{�̂Ȃǂ̒�`��kernel_cfg.c�ɐ������܂�\n"
            "  -z, --nonzero                : __EMPTY_LABEL�}�N���̎g�p�𐧌����܂�\n"
            "  -1.3  : TOPPERS/JSP rel 1.3 �p�̃R���t�B�M�����[�V�����t�@�C���𐶐����܂�\n");
        return;
    }

    checkOption("cfg","cfg");
    checkOption("id","id");

        /*
         *  �J�[�l���R���t�B�M�����[�V�������ʂ̃t�@�C�� (kernel_cfg.c) �̏����ݒ�
         */

    createKernelCfg();

        /*
         *  ID���t���ʂ̃t�@�C�� (kernel_id.h) �̏����ݒ�
         */

    createKernelID();

        /* ���̑��I�v�V���� */
    restrict_zero = findOption("z","zero");
    def_prototype = findOption("oproto","output-prototype");
    libstyle_include = findOption("il","include-libstyle");
    backward_compatible = findOption("1.3","1.3");
    
    checkOption("mcfg","minimize-cfg");
    checkOption("ZERO","ZERO");
    checkOption("obj", "dump-object");
    checkOption("ext");

    activateComponent();
}

void ConfigurationFileGenerator::onFatalExit(Directory & container)
{
        //��O�ňُ�I��������A�t�@�C���𐶐����Ȃ�
    dynamic_cast<MultipartStream *>(RuntimeObjectTable::getInstance(typeid(KernelCfg)))->disableOutput();
    dynamic_cast<MultipartStream *>(RuntimeObjectTable::getInstance(typeid(KernelID)))->disableOutput();
}

void ConfigurationFileGenerator::createObjectDefinition(MultipartStream * out, Directory & container, int flag, ...)
{
    Directory * scope;
    const char * buffer;
    string work;

    map<int, Directory *> sorter;
    map<int, Directory *>::iterator psorter;

    va_list vl;
    int i;

    Directory & id = container[string(PREFIX "/") + container.getKey().c_str()];

    if(container.size() == 0 && findOption("mcfg","minimize-cfg"))
    {
        if(!getOptionParameter().find("ext"))
            ExceptionMessage("Use of the extended option --minimize-cfg. Please use -ext option together.","--minimize�I�v�V�����͊g���@�\�ł��B�g�p����ɂ�-ext���w�肵�Ă��������B").throwException();
        return;
    }
    va_start(vl, flag);


        //�K�v�ȏ��̍쐬
    work = string(va_arg(vl, const char *));
    id["id"]  = work;
    transform(work.begin(), work.end(), work.begin(), toupper_function);
    id["ID"]  = work;
    

    if((flag & SHORT_ID) != 0)
    {
        work = string(va_arg(vl, const char *));
        id["sid"]  = work;
	for(i=0; i<(signed)work.size(); i++) {
	  if (work[i] >= 'a' && work[i] <= 'z')
	    work[i] = work[i] - 'a' + 'A';
	}
        id["SID"]  = work;
    }else
    {
        id["sid"] = id["id"].toString();
        id["SID"] = id["ID"].toString();
    }

    if(!backward_compatible)
        id["symbolprefix"] = "_kernel_";

    work = container.getKey();
    id["name"] = work;
    out->movePart(work);

        //�I�u�W�F�N�g�������֐���ǉ�
    if((flag & INIT) != 0 && container.size() != 0)
        container["/" OBJECT_INITIALIZER].addChild(new Directory(work));

    (*out) << "\n\t/* " << (Message("Object initializer [%]","�I�u�W�F�N�g�������u���b�N [%]") << work) << " */\n\n";

    if(((flag & HEADER) != 0) && backward_compatible)
        (*out) << "#include " << conv_includefile(work) << "\n\n";

    if((flag & TNUM) != 0)
    {
        (*out) << id.format("#define TNUM_$(ID)ID ") << container.size() << "\n\n";
        (*out) << id.format("const ID $(symbolprefix,)tmax_$(id)id = (TMIN_$(ID)ID + TNUM_$(ID)ID - 1);\n\n");
    }

    if((flag & TNUMNO) != 0)
    {
        (*out) << id.format("#define TNUM_$(ID)NO ") << container.size() << "\n\n";
        (*out) << id.format("const UINT $(symbolprefix,)tnum_$(id)no = TNUM_$(ID)NO;\n\n");
    }

        /* ID���Ƀ\�[�g (���̎��_�ŘA�Ԃ��m�肵�Ă���͂��Ȃ̂ŁC�`�F�b�N�͂��Ȃ�) */
    if((flag & (BUFFER|DEFINITION)) != 0)
    {
        const bool is_identifier = (flag & TNUMNO) == 0;

        i = 0;
        scope = container.getFirstChild();
        while(scope != 0)
        {
            if(is_identifier)
                sorter[scope->toInteger(i++)] = scope;
            else
                sorter[i++] = scope;

            scope = scope->getNext();
        }
    }

        //�v���g�^�C�v��`�̏o��
    if((flag & PROTOTYPE) != 0)
    {
        buffer = va_arg(vl, const char *);

        if(def_prototype)
        {
            set<string> func;
            set<string>::iterator pfunc;

            scope = container.getFirstChild();
            while(scope != NULL)
            {
                func.insert(scope->format(buffer));
                scope = scope->getNext();
            }

            pfunc = func.begin();
            while(pfunc != func.end())
            {
                (*out) << (*pfunc) << '\n';
                ++ pfunc;
            }
        }
    }

        //�o�b�t�@�̍쐬
    if((flag & BUFFER) != 0 && container.size() != 0)
    {
        buffer = va_arg(vl, const char *);
        psorter = sorter.begin();
        while(psorter != sorter.end())
        {
            (*out) << (*psorter).second->format(buffer) << '\n';
            ++ psorter;
        }
        (*out) << '\n';
    }

        //��`�u���b�N(xINIB)�̏o��
    if((flag & DEFINITION) != 0)
    {
        buffer = va_arg(vl, const char *);
        if(container.size() != 0)
        {
            (*out) << id.format("const $(SID)INIB $(symbolprefix,)$(sid)inib_table[TNUM_$(ID)") << ( (flag & TNUMNO) != 0  ? "NO" : "ID") << "] = {\n";
            psorter = sorter.begin();
            while(psorter != sorter.end())
            {
                (*out) << "\t{" << (*psorter).second->format(buffer) << '}';
                ++ psorter;
                if(psorter != sorter.end())
                    (*out) << ',';
                (*out) << '\n';
            }
            (*out) << "};\n\n";
        }else
            if( !restrict_zero )
                (*out) << id.format("__EMPTY_LABEL(const $(SID)INIB, $(symbolprefix,)$(sid)inib_table);\n");
    }

    if((flag & INITLIST) != 0)
    {
        Directory * node;

            /* �錾����ID�ԍ����\�[�g */
        sorter.clear();
        node = container.getFirstChild();
        while(node != NULL)
        {
            sorter.insert(pair<int,Directory*>(node->findChild("#order")->toInteger(), node));
            node = node->getNext();
        }

        *out << id.format("const ID $(symbolprefix,)$(sid)order_table[TNUM_$(ID)ID] = {");
        psorter = sorter.begin();
        while(psorter != sorter.end())
        {
            *out << psorter->second->toInteger();
            ++ psorter;
            if(psorter != sorter.end())
                *out << ',';
        }
        *out << "};\n\n";
    }

        //����u���b�N(xCB)�̏o��
    if((flag & CONTROLBLOCK) != 0)
    {
        if(container.size() != 0)
            (*out) << id.format("$(SID)CB $(symbolprefix,)$(sid)cb_table[TNUM_$(ID)ID];\n\n");
        else
            if( !restrict_zero )
                (*out) << id.format("__EMPTY_LABEL($(SID)CB, $(symbolprefix,)$(sid)cb_table);\n\n");
    }
}

void ConfigurationFileGenerator::body(Directory & container)
{
    Directory * scope;
    KernelCfg * out;
    string work;
    const bool varid_style = findOption("var","variable-id");

        /* kernel_id.h�̏o�� */
    serializeIdentifiers(varid_style);

        /* kernel_cfg.c�̏o�� */
    out = dynamic_cast<KernelCfg *>(RuntimeObjectTable::getInstance(typeid(KernelCfg)));
    if(out == 0) {
        ExceptionMessage("[Internal error] The stream buffer of kernel_cfg disappeared.","[�����G���[] �t�@�C���X�g���[�����J���܂��� (kernel_cfg.c)").throwException();
        return;
    }

        /* ���̒�`�����̍쐬 */
    serializeConfiguration_headerPart(*out);

        /* INCLUDE */
    out->movePart(INCLUDEFILE);
    scope = container(OBJECTTREE "/" INCLUDEFILE)->getFirstChild();
    (*out) << "\t/* " << Message("User specified include files","���[�U��`�̃C���N���[�h�t�@�C��") << "*/\n";
    while(scope != 0)
    {
        (*out) << "#include " << scope->toString() << '\n';
        scope = scope->getNext();
    }
    (*out) << '\n';

        /* TASK */
    work.assign("$(tskatr), (VP_INT)($(exinf)), (FP)($(task)), INT_PRIORITY($(itskpri)), __TROUND_STK_UNIT($(stksz)), __stack_$@, $(texatr), (FP)($(texrtn))");
    if(container["/cpu"].toString().compare("nios32") == 0)
        work += ", $(hi_limit), $(lo_limit)";
    createObjectDefinition(out, container[OBJECTTREE "/" TASK], HEADER|TNUM|SHORT_ID|BUFFER|DEFINITION|CONTROLBLOCK|INIT|PROTOTYPE|INITLIST,"tsk", "t", "void $(task)(VP_INT exinf);", "static __STK_UNIT __stack_$@[__TCOUNT_STK_UNIT($(stksz))];",work.c_str());

        /* SEMAPHORE */
    createObjectDefinition(out, container[OBJECTTREE "/" SEMAPHORE], HEADER|TNUM|DEFINITION|CONTROLBLOCK|INIT,"sem", "$(sematr), $(isemcnt), $(maxsem)");

        /* EVENTFLAG */
    createObjectDefinition(out, container[OBJECTTREE "/" EVENTFLAG], HEADER|TNUM|DEFINITION|CONTROLBLOCK|INIT,"flg", "$(flgatr), $(iflgptn)");

        /* DATAQUEUE */
    createObjectDefinition(out, container[OBJECTTREE "/" DATAQUEUE], HEADER|TNUM|BUFFER|DEFINITION|CONTROLBLOCK|INIT,"dtq", "#if ($(dtqcnt)) > 0\n  static VP_INT __dataqueue_$@[$(dtqcnt)];\n#else\n  #define __dataqueue_$@ NULL\n#endif","$(dtqatr), $(dtqcnt), __dataqueue_$@");

        /* MAILBOX */
    createObjectDefinition(out, container[OBJECTTREE "/" MAILBOX], HEADER|TNUM|DEFINITION|CONTROLBLOCK|INIT,"mbx","$(mbxatr), $(maxmpri)");

        /* FIXEDSIZEMEMORYPOOL */
    createObjectDefinition(out, container[OBJECTTREE "/" FIXEDSIZEMEMORYPOOL], HEADER|TNUM|BUFFER|DEFINITION|CONTROLBLOCK|INIT,"mpf","static __MPF_UNIT __fixedsize_memorypool_$@[__TCOUNT_MPF_UNIT($(blksz)) * (($(blkcnt)))];","$(mpfatr), __TROUND_MPF_UNIT($(blksz)), __fixedsize_memorypool_$@, (VP)((VB *)__fixedsize_memorypool_$@ + sizeof(__fixedsize_memorypool_$@))");

        /* CYCLICHANDLER */
    createObjectDefinition(out, container[OBJECTTREE "/" CYCLICHANDLER], HEADER|TNUM|DEFINITION|CONTROLBLOCK|INIT|PROTOTYPE,"cyc","void $(cychdr)(VP_INT exinf);","$(cycatr),$(exinf),(FP)($(cychdr)),$(cyctim),$(cycphs)");

        /* INTERRUPTHANDLER */
    createObjectDefinition(out, container[OBJECTTREE "/" INTERRUPTHANDLER], HEADER|BUFFER|TNUMNO|DEFINITION|INIT|PROTOTYPE,"inh","void $(inthdr)(void);","CFG_INTHDR_ENTRY($(inthdr));","$@,$(inhatr),(FP)CFG_INT_ENTRY($(inthdr))");

        /* EXCEPTIONHANDLER */
    createObjectDefinition(out, container[OBJECTTREE "/" EXCEPTIONHANDLER], HEADER|BUFFER|TNUMNO|DEFINITION|INIT|PROTOTYPE,"exc","void $(exchdr)(VP p_excinf);","CFG_EXCHDR_ENTRY($(exchdr));","$@,$(excatr),(FP)CFG_EXC_ENTRY($(exchdr))");


        /* �I�u�W�F�N�g���������[�`�� */
    out->movePart(OBJECT_INITIALIZER);
    (*out) << "\t/* " << Message("Object initialization routine","�I�u�W�F�N�g���������[�`��") << " */\n\n";
    (*out) << "void\n" << conv_kernelobject("object_initialize") << "(void)\n{\n";
    scope = container["/" OBJECT_INITIALIZER].getFirstChild();
    while(scope != 0)
    {
        (*out) << '\t' << conv_kernelobject(scope->toString() + "_initialize") << "();\n";
        scope = scope->getNext();
    }
    (*out) << "}\n\n";


        /* �������n���h�� */
    out->movePart(INITIALIZER);
    (*out) << "\t/* " << Message("Initialization handler","�������n���h���N�����[�`��") << " */\n\n";
    (*out) << "void\n" << conv_kernelobject("call_inirtn") << "(void)\n{\n";
    scope = container[OBJECTTREE "/" INITIALIZER].getFirstChild();
    while(scope != 0)
    {
        (*out) << scope->format("\t$(inirtn)( (VP_INT)($(exinf)) );\n");
        scope = scope->getNext();
    }
    (*out) << "}\n\n";

        /* �I���n���h�� */
    scope = container[OBJECTTREE "/"  TERMINATOR].getLastChild();
    if(!backward_compatible) {
        (*out) << "void\n" << conv_kernelobject("call_terrtn") << "(void)\n{\n";
        while(scope != 0)
        {
            (*out) << scope->format("\t$(terrtn)( (VP_INT)($(exinf)) );\n");
            scope = scope->getPrev();
        }
        (*out) << "}\n\n";
    }
    else {
        if(scope->size() != 0)
            ExceptionMessage("VATT_TER is not supported for TOPPERS/JSP rel 1.3 or earlier.",
                             "VATT_TER��TOPPERS/JSP rel 1.3�ȑO�ł̓T�|�[�g����܂���").throwException();
    }

    out->movePart("others");
    (*out) << "TMEVTN   " << conv_kernelobject("tmevt_heap") << "[TNUM_TSKID + TNUM_CYCID];\n\n";

    container["/object_initializer"].erase();

    string filename;
    if(findOption("obj","dump-object",&filename))
    {
        if(filename.empty())
            filename.assign("kernel_obj.dat");

        fstream f(filename.c_str(),ios::out|ios::binary);
        if(f.is_open())
        {
            container[OBJECTTREE].Store(&f);
            f.close();
        }else
            ExceptionMessage(" Failed to open the file % for storing object definitions"," �I�u�W�F�N�g�����i�[���邽�߂̃t�@�C��(%)���J���܂���") << filename << throwException;
    }

    out->enableOutput();
}


/* ======================================================================== */

