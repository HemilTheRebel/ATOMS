#pragma once

#include <iostream>
#include <array>
#include <cstring>
#include <time.h>


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}



using namespace std ;
const int numOfOptions = 3;

struct Question {
    std::string question;
    std::array<std::string, numOfOptions> options;
    int correctOption, chosenOption;

    Question(std::string question, std::array<std::string, numOfOptions> options, int correctOption) {
        this->question = question;
        this->options = options;
        this->correctOption = correctOption;
    }

    void display() {
        std::cout  << question << "\n";

        int counter = 1;
        for (auto option : options) {
            std::cout << counter << ". " << option << "\n";
            counter++;
        }
         std::cout << endl << "Enter Your Option: ";
         std::cin >> chosenOption;
    }

    bool isCorrect() {
        return chosenOption == correctOption;
    }
};


int randomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from, to);

    return dist6(rng);
}

std::vector<Question> getQuestions() {
    return {
        Question("A vertical column in the periodic table is called a :", {"valence", "branch", "group"}, 3),
        Question("About how many known elements are in the periodic table?", {"50", "118", "90"}, 2),
        Question("Elements in the periodic table are arranged by...", {"Atomic Number", "Atomic Weight", "Number of Neutrons"}, 1),
        Question("Which of these things are NOT listed in the periodic table?", {"Element Name or Symbol", "Atomic Weight", "Atomic Orbital Radius"}, 3),
        Question("Which scientist came up with the concept of a periodic table?", {"Jason Priestly", "Dmitri Mendeleev", "Albert Einstein"}, 2),
        Question("The rows of the periodic table are called periods.", {"True", "False", " "}, 1),
        Question("Which of these choices is NOT a family of elements?", {"Halogens", "All are Families of Elements", "Noble Gases"}, 2),
        Question("The atomic number of an element tells you the number of _____ in a neutral atom.", {"Neutrons", "Protons", "Electrons"}, 3),
        Question("The columns of the periodic table are called groups.", {"True", "False"}, 1),
        Question("You will find metals on the far right column of the periodic table.", {"True", "False"}, 2),
        Question("Although the order of elements is based on atomic number, vertical families share similar chemical properties.", {"True", "False"}, 1),
        Question("The majority of the elements in the periodic table are", {"Nonmetals", "Metals", "Metalloid"}, 2),
        Question("What is the capacity of the first electron shell?", {"two", "sixteen", "eight"}, 1),
        Question("The series of elements that contains mostly man made elements:", {"transition metals", "lanthanides", "actinides"}, 3),
        Question("Elements in the some group have", {"similar symbols", "the same number of neutrons", "the same number of valence electrons"}, 3),
        Question("How many valence electrons does calcium have?", {"one", "two", "three"}, 2),
        Question("How many valence electrons does boron have?", {"one", "three", "two"}, 2),
        Question("The transition elements are located", {"Middle", "Left", "Right"}, 1),
        Question("The element with atomic number 12 is ", {"carbon", "magnesium", "boron"}, 2),

    };
}

void removeQuestion(std::vector<Question> &questions, int index) {
    questions.erase(questions.begin() + index);
}

int quiz()
{

    system("cls");
    int correctAnswers = 0,i;

    std::vector<Question> questionsLeft = getQuestions();


    for (i=1;i<=10;i++) {
        int random = randomNumber(0, questionsLeft.size() - 1);

        Question question = questionsLeft.at(random);

        question.display();

        if (question.isCorrect()) {
            correctAnswers++;

            std::cout << "\nCorrect Answer!!!\n";
        } else {
            std::cout << "\nWrong Answer :(\n";
        }

        removeQuestion(questionsLeft, random);
        system("cls");

    }

    std::cout << " Your Score Is : "  << correctAnswers << endl ;
}

const char* display1(){
return("Hydrogen:- \n"
"1.)It is a colourless,odourless and tasteless gas."
"2.)It is the lightest gas known. \n"
"3.)It is only very slightly soluble in water. \n"
"4.)It can be liquefied under high pressure and at low temperature. \n");

 }

const char* display2(){
return("Helium:-  \n"
"1.)It is a colourless,odourless and tasteless gas. \n"
"2.)It is the lightest gas known. \n"
"3.)It is used for providing an inert atmosphere. \n"
"4.)It is non-inflammable.\n" );
}



const char* display3(){
return("Lithium:- \n"
"1.)Lithium is a silvery white metal. \n"
"2.)It is quite soft. \n"
"3.)Lithium imparts crimson red colour to the flame. \n"
"4.)It is one of the strongest reducing agent. \n");
}


const char* display4(){
return("Beryllium:- \n"
"1.)Beryllium is very hard in nature. \n"
"2.)It is used as a scavanger in metallurgy. \n"
"3.)It is used in X-Ray window. \n"
"4.)It is used for making electrodes of neon signs. \n");
}



const char* display5(){
return("Boron:- \n"
"1.)Boron exist in three allotropic forms. \n"
"2.)Boron is a poor conductor of electricity. \n"
"3.)Boron is quite inert towards water. \n");
}



const char* display6(){
return("Carbon:- \n"
"1.)It is a non-metallic element. \n"
"2.)It occurs both in free as well as combined state. \n"
"3.)Air also contain carbon as carbon-di-oxide. \n"
"4.)In free state it occurs as diamond,coal and graphite. \n"
"5.)Carbon forms hydrites known as hydrocarbon. \n");
}



const char* display7(){
return("Nitrogen:- \7n"
"1.)It is a typical non-metal. \n"
"2.)It exists as diatomic molecule. \n"
"3.)It is highly electronegative element. \n"
"4.)The oxidation state of nitrogen varies from -3 to +5. \n"
"5.)Molecular nitrogen is called dinitrogen. \n");
}



const char* display8(){
return("Oxygen:- \n"
"1.)It is a non-metal. \n"
"2.)It is paramagnatic in nature. \n"
"3.)It is most abundant element in earth's crust. \n"
"4.)It is di-atomic in nature. \n"
"5.)Molecular oxygen is also called dioxygen. \n");
}



const char* display9(){
return("Fluorine:- \n"
"1.)It is a non-metallic element. \n"
"2.)It is most electronegative in nature. \n"
"3.)It is used in the preparation of uranium hexafluoride. \n"
"4.)In nature it is not found in free state. \n"
"5.)It is used as plastic teflon. \n");
}



const char* display10(){
return("Neon:-  \n"
"1.)It is a gas."
"2.)It is widely used in sign boards."
"3.)It is used in T.V.,radio,photography and warning signals. \n"
"4.)It produces an orange glow when an electric current is passed. \n"
"5.)Neon lights are used as beacon lights for pilots. \n");
}



const char* display11(){
return("Sodium:- \n"
"1.)It occurs only in the combined form."
"2.)NaCl,common salt found as rock salt, in sea water."
"3.)Sodium nitrate as chili saltpetre or Caliche in Chile."
"4.)Sodium carbonate is found as an efflorescent substance."
"5.)Sodium is extracted by electrolysis of fused caustic soda.");
}



const char* display12(){
return("Magnesium:- \n"
"1.)It is used in manufacture of alloys. \n"
"2.)It is extracted by reduction of MgO. \n"
"3.)It is used as a reducing agent for boron and silicon. \n"
"4.)It is used as a de-oxidiser in metallurgy. \n"
"5.)It is used as a fuse in alumino-thermite process. \n"
"6.)It is used in flash light photography and in fire-works. \n");
}



const char* display13(){
return("Aluminium:- \n"
"1.)It is a reactive metal. \n"
"2.)It exists in combined state. \n"
"3.)It is present in earth's crust & its relative abundance is 8.3. \n"
"4.)Aluminium is extracted from its ore bauxite. \n"
"5.)It is not effected by atmosphere & do not decompose water. \n");
}



const char* display14(){
return("Silicon:- \n"
"1.)Silicon is very abundant element. \n"
"2.)It is present in earth's crust to the extexnt of 28%. \n"
"3.)It is present in the form of silica. \n"
"4.)It is used in semi-conductor. \n"
"5.)It exists in two allotropic forms i.e. amorphous and crystalline. \n");
}


const char* display15(){
return("Phosphorus:- \n"
"1.)It is a reactive non-metal. \n"
"2.)It is the tenth element in the order of abundance in earth crust. \n"
"3.)It exists in combined form. \n"
"4.)It constitutes our bones,teeth,muscles,brain & nerve tissue. \n"
"5.)In the form of phospholipids it is present in milk,egg,fish,etc. \n");
}



const char* display16(){
return("Sulphur:- \n"
"1.)It is present in small proportion. \n"
"2.)It is used as disinfectant for destroying bacteria,fungi. \n"
"3.)It is used in vulcanisation of rubber. \n"
"4.)It is a constituent of medicines for skin diseases. \n"
"5.)It is used in manufacture of matches,fire-works,etc. \n");
}



const char* display17(){
return("Chlorine:- \n"
"1.)It is a non-metallic element. \n"
"2.)It is used in bleaching textile,yarn,paper,pulp. \n"
"3.)It is used in the sterilization of drinking water. \n"
"4.)It is used in the manufacture of vinyl chloride. \n"
"5.)It is used in preparing insecticides such as D.D.T. & B.H.C. \n");
}



const char* display18(){
return("Argon:- \n"
"1.)It is a noble-gas. \n"
"2.)It is found in traces in the certain spring water. \n"
"3.)It is used in metal filament electric lamps. \n"
"4.)It is used in thermionic tubes. \n"
"5.)It is used for creating inert atmosphere. \n");
}



const char* display19(){
return("Potassium:- \n"
"1.)It occurs in combined form. \n"
"2.)Potassium carbonate is a constituent of wood ashes. \n"
"3.)It is prepared by electrolysis of fused potassium cyanide. \n"
"4.)It is a silvery white metal. \n"
"5.)It is lighter & softer than sodium. \n");
}



const char* display20(){
return("Calcium:- \n"
"1.)It forms bivalent ions. \n"
"2.)It imparts brick red colour to flame. \n"
"3.)It's melting point & boiling point is 1112K & 1767K. \n"
"4.)It's electronegativity is 1. \n"
"5.)Its first & second ionisation energies are 590 & 1146KJ/mol. \n"
"6.)It's density is 1.05g/c.c  \n.");
}



const char* display21(){
return("Scandium:- \n"
"1.)It's atomic radius is 144 p.m. \n"
"2.)It exhibits +2 & +3 oxidation states. \n "
"3.)Colour of it's ion is white. \n"
"4.)It's ionisation energy is 631KJ/mol. \n"
"5.)It is the first element of d-block element. \n");
}



const char* display22(){
return("Titanium:- \n"
"1.)Its atomic radii is 132pm. \n"
"2.)It contains two unpaired electrons. \n"
"3.)It exhibits +2 & +3 oxidation states. \n"
"4.)It's ionisation energy is 656 KJ/mol. \n"
"5.)It is used to extract pure metals. \n");
}



const char* display23(){
return("Vanadium:- \n"
"1.)It's magnatic moment is 2.76 B.M. \n"
"2.)It exhibits stable +5 oxidation state. \n"
"3.)It forms green & white ions. \n"
"4.)It's value of electrode potential is -1.20 V. \n");
}



const char* display24(){
return("Chromium:- \n"
"1.)It's magnetic moment is 3.86 B.M. \n"
"2.)It is used in making of alloys & in plating of metals. \n"
"3.)Dichromate ion is used as volumetric reagent. \n"
"4.)It has maximum no. of unpaired electrons. \n"
"5.)It forms basic & amphoteric oxides. \n"
"6.)It's heat of sublimation is 318 KJ/mol. \n");
}



const char* display25(){
return("Manganese:- \n"
"1.)It has abnormally low melting point. \n"
"2.)It's important ores are pyrolusite and braunite. \n"
"3.)It is used to manufacture steel, rail lines etc. \n"
"4.)It is used in making manganese bronze used in parts of ships. \n"
"5.)It is the 14th most abundant element in the earth's crust. \n");
}



const char* display26(){
return("Iron:- \n"
"1.)It is used in formation of various alloys. \n"
"2.)It exhibits +2 & +3 oxidation states. \n"
"3.)It forms various non-stoichiometric oxides. \n"
"4.)It's electrode potential is -0.44 V. \n"
"5.)It is used as catalyst in many processes. \n");
}



const char* display27(){
return("Cobalt:- \n"
"1.)It forms pink coloured ions. \n"
"2.)Cobalt salts catalyse the decomposition of bleaching powder. \n"
"3.)It forms the basic oxide CaO. \n"
"4.)It is known as a ferrous metal. \n"
"5.)It's ionisation energy is 758 KJ/mol. \n"
"6.)It forms various complexes. \n");
}



const char* display28(){
return("Nickel:- \n"
"1.)It forms green coloured ions. \n"
"2.)It exhibits +2,+3,+4 oxidation states. \n"
"3.)It is used in hydrogenation reaction in organic chemistry. \n"
"4.)It's heat of sublimation is 397 KJ/mol. \n"
"5.)It has atomic radii of 115pm. \n"
"6.)It's ionisation energy is 736 KJ/mol. \n");
}



const char* display29(){
return("Copper:- \n"
"1.)It is a dimagnetic substance. \n"
"2.)It occurs in free as well as in combined form. \n"
"3.)It is used in making copper wires and electrical goods. \n"
"4.)It exhibits +1 and +2 oxidation state. \n"
"5.)It has an electrode potential of -0.34 V. \n"
"6.)It forms blue and white coloured ions. \n");
}



const char* display30(){
return("Zinc:- \n"
"1.)Zinc blend is usually the main ore. \n"
"2.)Zinc is a metal. \n"
"3.)Zinc is a moderately hard,brittle element. \n"
"4.)Zinc is a d-block element. \n"
"5.)It's magnetic moment is 0. \n"
"6.)It is used to galvanize iron. \n");
}



const char* display31(){
return("Gallium:- \n"
"1.)It is a shining greyish white metal. \n"
"2.)it has a density of 5.9 in solid and 6.095 in liquid state. \n"
"3.)It has a very low melting point of 30^C. \n"
"4.)It is a very rare element. \n"
"5.)It is a element of p-block. \n"
"6.)It's atomic radii is 135pm. \n");
}



const char* display32(){
return("Germanium:- \n"
"1.)It's atomic radius is 122 pm . \n"
"2.)It's bond energy is 167.2 KJ/mol. \n"
"3.)It is used as semi-conductor. \n"
"4.)It has bond gap of 0.7eV. \n"
"5.)It's electronegativity is 1.8. \n"
"6.)It's melting and boiling points are 1218K and 3123K. \n");
}



const char* display33(){
return("Arsenic:- \n"
"1.)It is an element of p-block. \n"
"2.)It exists in yellow and grey colour. \n"
"3.)It's electronegativity is 2. \n"
"4.)It is a highly poisonous substance. \n"
"5.)It is one of a banned element in school labs. \n"
"6.)It's density is 50.78g/c.c. \n");
}



const char* display34(){
return("Selenium:- \n"
"1.)It is an element of p-block. \n"
"2.)It's atomic radius is 116pm. \n"
"3.)It's density in solid state is 4.79g/c.c. \n"
"4.)It finds use in fire proofing electrical fittings. \n"
"5.)It finds use in medicine. \n"
"6.)It forms various hallides. \n");
}



const char* display35(){
return("Bromine:- \n"
"1.)It's atomic radius is 101.4pm. \n"
"2.)It's ionisation energy is 1142 KJ/mol. \n"
"3.)It is reddish brown in colour. \n"
"4.)It makes bromo compounds in organic chemistry. \n"
"5.)It finds use in medicine. \n"
"6.)It is a liquid with obnoxious smell \n");
}



const char* display36(){
return("Krypton:- \n"
"1.)It is a noble gas. \n"
"2.)It is attached by weak Van der wall forces. \n"
"3.)It does not exist as adiatomic molecule. \n"
"4.)It is a by products in nuclear reactors. \n"
"5.)It is a gas with suffocating smell. \n"
"6.)It is a colourless,tasteless and odourless gas. \n");
}



const char* display37(){
return("Rubidium:- \n"
"1.)It catches fire spontaneously in air. \n"
"2.)It boils at 696K giving bluish vapours. \n"
"3.)It is a silvery white metal which melts at 311K. \n"
"4.)It forms complex salts with halogens. \n"
"5.)It gives a series of insoluble salts. \n"
"6.)It's compounds are isomorphous with potassium compounds. \n");
}



const char* display38(){
return("Stroncium:- \n"
"1.)It was discovered by Davy. \n"
"2.)It is a soft white metal & possess specific gravity of 2.5. \n"
"3.)It is malleable and ductile. \n"
"4.)It is comparitively more active than calcium. \n"
"5.)It's nitrates are colourless crystalline solids. \n"
"6.)It is not acted upon by fusion with alkali carbonates. \n");
}


const char* display39(){
return("Yttrium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}



const char* display40(){
return("Zirconium:- \n"
"1.)It is a silvery white metal. \n"
"2.)It's oxide is a refractory material. \n"
"3.)When heated in air it give black oxide. \n"
"4.)It is not acted upon by fusion with alkali carbonates. \n"
"5.)It's nitrate or chloride solution on hydrolysis give collidal. \n");
}



const char* display41(){
return("Niobium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}



const char* display42(){
return("Molybdenum:- \n"
"1.)It acts as good adsorbant. \n"
"2.)It is a grey metallic powder which remains untarnished in air. \n"
"3.)When heated it gradually passes into oxide. \n"
"4.)It is insoluble in HCl,HF & dil. sulphuric acid. \n"
"5.)It is soluble in nitric acid, conc. sulphuric acid & aqua regia. \n"
"6.)It is used as a catalyst in various chemical reactios. \n");
}



const char* display43(){
return("Technetium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}



const char* display44(){
return("Ruthenium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}


const char* display45(){
return("Rhodium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display46(){
return("Palladium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display47(){
return("Silver:- \n"
"1.)It is a lustrous white metal. \n"
"2.).It is a good conductor of heat and electricity. \n"
"3.)It finds use in ornaments. \n"
"4.)The principal ore of silver is silver glance. \n"
"5.)It is a malleable and ductile. \n"
"6.)It does not react with dilute acids. \n");
}

const char* display48(){
return("Cadmium:- \n"
"1.)It is a soft bluish white metal. \n"
"2.)It gets oxidised with moist air but when heated it yields CdO. \n"
"3.)It melts at 594K and boils at 1040K. \n"
"4.)With hallogen it forms cadmium hallide. \n"
"5.)It reacts with nitric acid and sulphuric acid. \n");
}

const char* display49(){
return("Indium:- \n"
"1.)It is a lustrous white metal. \n"
"2.)It is malleable and ductile but becomes brittle at about 473K. \n"
"3.)It is not attacked by organic acids. \n"
"4.)It exhibits three allotropic forms. \n"
"5.)It reacts with sulphur to form stannic sulphide. \n");
}

const char* display50(){
return("Tin:- \n"
"1.)It is a lustrous white metal. \n"
"2.)It is not attacked by organic acids. \n"
"3.)It exibits three allotropic forms. \n"
"4.)It reacts with sulphur to form stannic sulphide. \n"
"5.)It is melleable & ductile but becomes brittle at about 473k. \n");
}

const char* display51(){
return("Antimony:- \n"
"1.)It burns spontaneously with chlorine. \n"
"2.)It is hard,brittle and white lustrous metal. \n"
"3.)It forms alloy with tin,lead and copper. \n"
"4.)At ordinary temperature it is not affected by air. \n"
"5.)Pure antimony does not dissolve in HCl. \n");
}

const char* display52(){
return("Tellurium:- \n"
"1.)It is poor conductor of electricity. \n"
"2.)Powdered Te is grey in colour. \n"
"3.)On heating it becomes crystalline. \n"
"4.)It has highest electrical resistance in metals. \n"
"5.)It has a metallic appearance. \n");
}

const char* display53(){
return("Iodine:- \n"
"1.)It is spriangly soluble in water. \n"
"2.)Iodine warmed with alcohol forms iodoform. \n"
"3.)It gives shining black cryastals with metallic lusture. \n"
"4.)It is strongest reducing halogen. \n"
"5.)Iodine solution is decoloursed by alkali solution. \n");
}

const char* display54(){
return("Xenon:- \n"
"1.)It is a noble gas. \n"
"2.)It forms a number of stable compounds. \n"
"3.)It is a monoatomic gas at room temprature. \n"
"4.)It has zero valency. \n"
"5.)Xe oxides are formed by reaction of xenon flouride with water. \n");
}

const char* display55(){
return("Cesium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display56(){
return("Barium:- \n"
"1.)Its density is 3.62g/c.c. \n"
"2.)Its electronegativity is 0.89. \n"
"3.)Its atomic radius is 222pm. \n"
"4.)It has melting point & boiling point 1000k &2123k respectively. \n"
"5.)It imparts Grassy green colour to the flame. \n");
}

const char* display57(){
return("lanthanum:- \n"
"1.)Its ionic radius is 103pm. \n"
"2.)It exhibits oxidation state of +3. \n"
"3.)Its atomic radius is 187pm. \n"
"4.)It is good conductor of heat & electricity. \n"
"5.)It is resistant to corrosion. \n");
}

const char* display58(){
return("Cerium:- \n"
"1.)It is a good oxidising agent. \n"
"2.)Forms alloys readily with other metals. \n"
"3.)It has high electropositive character. \n"
"4.)It has low tendancy to form complexes. \n"
"5.)It has very high melting point. \n");
}

const char* display59(){
return("Praseodymium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display60(){
return("Neodymium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display61(){
return("Promethium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display62(){
return("Samarium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display63(){
return("Europium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display64(){
return("Gadolinium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display65(){
return("Terbium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display66(){
return("Dysprosium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display67(){
return("Holmium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display68(){
return("Erbium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display69(){
return("Thulium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display70(){
return("Ytterbium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display71(){
return("Lutetium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display72(){
return("Hafnium:- \n"
"1.)It is a silvery white metal. \n"
"2.)It occurs in minerals. \n"
"3.)It exhibits +3 & +4 oxidation states. \n");
}

const char* display73(){
return("Tantalum:- \n"
"1.)It is resistant to corrosion. \n"
"2.)It is used in surgical vessel & as an anlytical weights. \n"
"3.)It's atomic radii is 134pm. \n");
}

const char* display74(){
return("Tungsten:- \n"
"1.)It is hardest metal known. \n"
"2.)It's filament is used in incandescent bulbs. \n"
"3.)It's alloy forms steel for high speed tools. \n");
}

const char* display75(){
return("Rhenium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display76(){
return("Osmium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display77(){
return("Iridium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display78(){
return("Platinium:- \n"
"1.)It is very less reactive metal. \n"
"2.)It shows catalytic properties in contact process. \n"
"3.)It is used in the manufacture of hydrogen electrodes. \n");
}

const char* display79(){
return("Gold:- \n"
"1.)It is known as coinage metal. \n"
"2.)It is used in jwellery. \n"
"3.)It has high electrical & thermal conductivity. \n");
}

const char* display80(){
return("Mercury:- \n"
"1.)It is used in thermometers. \n"
"2.)It is useful in making electrical contacts. \n"
"3.)It is used in preparing amalgams of Cu,Ag,etc. \n"
"4.)It is used as electrolyte in various processes. \n");
}

const char* display81(){
return("Thalium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display82(){
return("Lead:- \n"
"1.)It is used for making containers. \n"
"2.)It's atomic radius is 146pm. \n"
"3.)It's electronegativity is 1.9. \n");
}

const char* display83(){
return("Bismuth:- \n"
"1.)It's density is 9.3g/c.c. \n"
"2.)It's atomic radius is 150pm. \n");
}

const char* display84(){
return("Polonium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display85(){
return("Astatine:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display86(){
return("Radon:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display87(){
return("Francium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display88(){
return("Radium:- \n"
"1.)It's density is 6g/c.c. \n"
"2.)It's ionic radii is 1.52pm. \n"
"3.)It is a radioactive element. \n"
"4.)It was discovered by Madam Curie. \n");
}

const char* display89(){
return("Actinum:-  \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display90(){
return("Thorium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display91(){
return("Protactinum:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display92(){
return("Uranium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display93(){
return("Neptunium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display94(){
return("Plutonium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display95(){
return("Americium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display96(){
return("Curium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display97(){
return("Berkelium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display98(){
return("Californium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display99(){
return("Einsteinium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display100(){
return("Fermium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display101(){
return("Mendelevium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display102(){
return("Nobelium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display103(){
return("Lawrencium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display104(){
return("Unnilquadium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display105(){
return("Unnilpentium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display106(){
return("Unnilhexium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR \n.");
}

const char* display107(){
return("Unnilseptium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display108(){
return("Unniloctium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display109(){
return("Unnilennium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display110(){
return("Ununnilium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display111(){
return("Unununium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display112(){
return("Unubium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display113(){
return(" \n THIS ELEMENT IS NOT KNOWN SO FAR.");
}

const char* display114(){
return("Ununquadium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display115(){
return("Ununhexium:- \n "
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

const char* display116(){
return("Ununoctium:- \n"
"THIS ELEMENT IS NOT KNOWN SO FAR. \n");
}

void Info()
{
 char a[10];
cout<<"Enter name of the element:"<<endl;
cin>>a;
if(strcmp("H",a)==0){
cout<<display1();};
if(strcmp("He",a)==0){
cout<<display2();};
if(strcmp("Li",a)==0){
cout<<display3();};
if(strcmp("Be",a)==0){
cout<<display4();};
if(strcmp("B",a)==0){
cout<<display5();};
if(strcmp("C",a)==0){
cout<<display6();};
if(strcmp("N",a)==0){
cout<<display7();};
if(strcmp("O",a)==0){
cout<<display8();};
if(strcmp("F",a)==0){
cout<<display9();};
if(strcmp("Ne",a)==0){
cout<<display10();};
if(strcmp("Na",a)==0){
cout<<display11();};
if(strcmp("Mg",a)==0){
cout<<display12();};
if(strcmp("Al",a)==0){
cout<<display13();};
if(strcmp("Si",a)==0){
cout<<display14();};
if(strcmp("P",a)==0){
cout<<display15();};
if(strcmp("S",a)==0){
cout<<display16();};
if(strcmp("Cl",a)==0){
cout<<display17();};
if(strcmp("Ar",a)==0){
cout<<display18();};
if(strcmp("K",a)==0){
cout<<display19();};
if(strcmp("Ca",a)==0){
cout<<display20();};
if(strcmp("Sc",a)==0){
cout<<display21();};
if(strcmp("Ti",a)==0){
cout<<display22();};
if(strcmp("V",a)==0){
cout<<display23();};
if(strcmp("Cr",a)==0){
cout<<display24();};
if(strcmp("Mn",a)==0){
cout<<display25();};
if(strcmp("Fe",a)==0){
cout<<display26();};
if(strcmp("Co",a)==0){
cout<<display27();};
if(strcmp("Ni",a)==0){
cout<<display28();};
if(strcmp("Cu",a)==0){
cout<<display29();};
if(strcmp("Zn",a)==0){
cout<<display30();};
if(strcmp("Ga",a)==0){
cout<<display31();};
if(strcmp("Ge",a)==0){
cout<<display32();};
if(strcmp("As",a)==0){
cout<<display33();};
if(strcmp("Se",a)==0){
cout<<display34();};
if(strcmp("Br",a)==0){
cout<<display35();};
if(strcmp("Kr",a)==0){
cout<<display36();};
if(strcmp("Rb",a)==0){
cout<<display37();};
if(strcmp("Sr",a)==0){
cout<<display38();};
if(strcmp("Y",a)==0){
cout<<display39();};
if(strcmp("Zr",a)==0){
cout<<display40();};
if(strcmp("Nb",a)==0){
cout<<display41();};
if(strcmp("Mo",a)==0){
cout<<display42();};
if(strcmp("Tc",a)==0){
cout<<display43();};
if(strcmp("Ru",a)==0){
cout<<display44();};
if(strcmp("Rh",a)==0){
cout<<display45();};
if(strcmp("Pd",a)==0){
cout<<display46();};
if(strcmp("Ag",a)==0){
cout<<display47();};
if(strcmp("Cd",a)==0){
cout<<display48();};
if(strcmp("In",a)==0){
cout<<display49();};
if(strcmp("Sn",a)==0){
cout<<display50();};
if(strcmp("Sb",a)==0){
cout<<display51();};
if(strcmp("Te",a)==0){
cout<<display52();};
if(strcmp("I",a)==0){
cout<<display53();};
if(strcmp("Xe",a)==0){
cout<<display54();};
if(strcmp("Cs",a)==0){
cout<<display55();};
if(strcmp("Ba",a)==0){
cout<<display56();};
if(strcmp("La",a)==0){
cout<<display57();};
if(strcmp("Ce",a)==0){
cout<<display58();};
if(strcmp("Pr",a)==0){
cout<<display59();};
if(strcmp("Nd",a)==0){
cout<<display60();};
if(strcmp("Pm",a)==0){
cout<<display61();};
if(strcmp("Sm",a)==0){
cout<<display62();};
if(strcmp("Eu",a)==0){
cout<<display63();};
if(strcmp("Gd",a)==0){
cout<<display64();};
if(strcmp("Tb",a)==0){
cout<<display65();};
if(strcmp("Dy",a)==0){
cout<<display66();};
if(strcmp("Ho",a)==0){
cout<<display67();};
if(strcmp("Er",a)==0){
cout<<display68();};
if(strcmp("Tm",a)==0){
cout<<display69();};
if(strcmp("Yb",a)==0){
cout<<display70();};
if(strcmp("Lu",a)==0){
cout<<display71();};
if(strcmp("Hf",a)==0){
cout<<display72();};
if(strcmp("Ta",a)==0){
cout<<display73();};
if(strcmp("W",a)==0){
cout<<display74();};
if(strcmp("Re",a)==0){
cout<<display75();};
if(strcmp("Os",a)==0){
cout<<display76();};
if(strcmp("Ir",a)==0){
cout<<display77();};
if(strcmp("Pt",a)==0){
cout<<display78();};
if(strcmp("Au",a)==0){
cout<<display79();};
if(strcmp("Hg",a)==0){
cout<<display80();};
if(strcmp("TL",a)==0){
cout<<display81();};
if(strcmp("Pb",a)==0){
cout<<display82();};
if(strcmp("Bi",a)==0){
cout<<display83();};
if(strcmp("Po",a)==0){
cout<<display84();};
if(strcmp("At",a)==0){
cout<<display85();};
if(strcmp("Rn",a)==0){
cout<<display86();};
if(strcmp("Fr",a)==0){
cout<<display87();};
if(strcmp("Ra",a)==0){
cout<<display88();};
if(strcmp("Ac",a)==0){
cout<<display89();};
if(strcmp("Th",a)==0){
cout<<display90();};
if(strcmp("Pa",a)==0){
cout<<display91();};
if(strcmp("U",a)==0){
cout<<display92();};
if(strcmp("Np",a)==0){
cout<<display93();};
if(strcmp("Pu",a)==0){
cout<<display94();};
if(strcmp("Am",a)==0){
cout<<display95();};
if(strcmp("Cm",a)==0){
cout<<display96();};
if(strcmp("Bk",a)==0){
cout<<display97();};
if(strcmp("Cf",a)==0){
cout<<display98();};
if(strcmp("Es",a)==0){
cout<<display99();};
if(strcmp("Fm",a)==0){
cout<<display100();};
if(strcmp("Md",a)==0){
cout<<display101();};
if(strcmp("No",a)==0){
cout<<display102();};
if(strcmp("Lr",a)==0){
cout<<display103();};
if(strcmp("unnilquadium",a)==0){
cout<<display104();};
if(strcmp("unnilpentilum",a)==0){
cout<<display105();};
if(strcmp("unnilhexium",a)==0){
cout<<display106();};
if(strcmp("unnilseptium",a)==0){
cout<<display107();};
if(strcmp("unniloctium",a)==0){
cout<<display108();};
if(strcmp("unnilennium",a)==0){
cout<<display109();};
if(strcmp("ununnilum",a)==0){
cout<<display110();};
if(strcmp("unununmium",a)==0){
cout<<display111();};
if(strcmp("unubium",a)==0){
cout<<display112();};
if(strcmp("",a)==0){
cout<<display113();};
if(strcmp("ununquadium",a)==0){
cout<<display114();};
if(strcmp("ununhexim",a)==0){
cout<<display115();};
if(strcmp("ununoctium",a)==0){
cout<<display116();};
}


void Information()
    {

std::cout << "==================================================================================================================================================================\n";
std::cout << "-------------------------------------------------------------THE PERODIC TABLE------------------------------------------------------------------------------------\n";
std::cout << "==================================================================================================================================================================\n";
std::cout << "\n";
std::cout << "\n";
std::cout << "\n";
std::cout << "                  |------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "                  |  1   |   2  |   3 | |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  11  |  12  |  13  |  14  |  15  |  16  |  17  |  18  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   1   |  H   |      |     | |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  He  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   2   |  Li  |  Be  |     | |      |      |      |      |      |      |      |      |      |  B   |  C   |   N  |  O   |   F  |  Ne  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   3   |  Na  |  Mg  |     | |      |      |      |      |      |      |      |      |      |  Al  |  Si  |   P  |  S   |  Cl  |  Ar  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   4   |  K   |  Ca  |  Sc | |  Ti  |  V   |  Cr  |  Mn  |  Fe  |  Co  |  Ni  |  Cu  |  Zn  |  Ga  |  Ge  |  As  |  Se  |  Br  |  Kr  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   5   |  Rb  |  Sr  |  Y  | |  Zr  |  Nb  |  Mo  |  Tc  |  Ru  |  Rh  |  Pd  |  Ag  |  Cd  |  In  |  Sn  |  Sb  |  Te  |  I   |  Xe  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   6   |  Cs  |  Ba  |  La | |  Hf  |  Ta  |  W   |  Re  |  Os  |  Ir  |  Pt  |  Au  |  Hg  |  Ti  |  Pb  |  Bi  |  Po  |  At  |  Rn  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |   7   |  Fr  |  Ra  |  Ac | |  Rf  |  Db  |  Sg  |  Bh  |  Hs  |  Mt  |  Ds  |  Rg  |  Cn  |  Nh  |  Fl  |  Mc  |  Lv  |  Ts  |  Og  \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |       |      |      |     | |  Ce  |  Pr  |  Nd  |  Pm  |  Sm  |  Eu  |  Gd  |  Tb  |  Dy  |  Ho  |  Er  |  Tm  |  Yb  |  Lu  |      \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "          |       |      |      |     | |  Th  |  Pa  |  U   |  Np  |  Pu  |  Am  |  Cm  |  Bk  |  Cf  |  Es  |  Fm  |  Md  |  No  |  Lr  |      \n";
std::cout << "          |-------|------|------|-----| |------|------|------|------|------|------|------|------|------|------|------|------|------|------|------\n";
std::cout << "\n";
std::cout << "\n";
std::cout << "==================================================================================================================================================================\n";
std::cout << "\n";
Info();
}

void start_menu()
{
    delay(5000);
    system("cls");
cout << "----------------++------------+++++++++++++++++----------++----------+++--------------+++-----++++++++++++++++-----\n";
cout << "--------------++--++----------+++++++++++++++++-------++----++-------++-++----------++-++-----++++++++++++++++-----\n";
cout << "-------------++----++----------------+++-------------++------++------++---++------++---++-----+++++----------------\n";
cout << "------------++------++---------------+++------------++--------++-----++-----++--++-----++---------+++--------------\n";
cout << "-----------++--------++--------------+++------------++--------++-----++-------++-------++------------+++-----------\n";
cout << "----------++----------++-------------+++------------++--------++-----++----------------++--------------+++---------\n";
cout << "---------++------------++------------+++------------++--------++-----++----------------++----------------+++-------\n";
cout << "--------++--------------++-----------+++-------------++------++------++----------------++------------------++++----\n";
cout << "-------++----------------++----------+++--------------++----++-------++----------------++-----+++++++++++++++++----\n";
cout << "------++------------------++---------+++-----------------++----------++----------------++-----+++++++++++++++++----\n";

std::cout << "1.Information\n";
std::cout << "2.Quiz\n";
std::cout << "3.Exit\n";

}









