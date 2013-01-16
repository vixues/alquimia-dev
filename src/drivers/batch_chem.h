/* -*-  mode: c++; c-default-style: "google"; indent-tabs-mode: nil -*- */
#ifndef ALQUIMIA_DRIVERS_CC_BATCH_CHEM_H_
#define ALQUIMIA_DRIVERS_CC_BATCH_CHEM_H_

#include <string>
#include <vector>

#include "alquimia_containers.h"

#include "demo_containers.h"

int CommandLineOptions(int argc, char** argv,
                       std::string* verbosity_name,
                       std::string* input_file_name,
                       std::string* template_file_name,
                       bool* debug_batch_driver);

void SetupChemistryOutput(void);

void SetupTextOutput(const std::string& use_text_output,
                     const std::string& output_time_units,
                     const std::string& input_file_name,
                     std::fstream* text_output, char* time_units,
                     double* time_units_conversion);

void WriteTextOutputHeader(std::fstream* text_output,
                           const char time_units,
                           const std::vector<std::string>& names,
                           const bool using_sorption);

void WriteTextOutput(std::fstream* text_output,
                     const double time,
                     const AlquimiaState_C& state);

void SetupAlquimiaState(
    const alquimia::drivers::utilities::DemoState& demo_state,
    const AlquimiaSizes_C& alquimia_sizes,
    AlquimiaState_C* alquimia_state);

void SetupAlquimiaMaterialProperties(
    const alquimia::drivers::utilities::DemoMaterialProperties& material_props,
    const AlquimiaSizes_C& alquimia_sizes,
    AlquimiaMaterialProperties_C* alquimia_material_props);

void SetupAlquimiaMetaData(
    const AlquimiaSizes_C& alquimia_sizes,
    AlquimiaMetaData_C* alquimia_meta_data);

void SetupAlquimiaConditions(
    const alquimia::drivers::utilities::DemoConditions& demo_conditions,
    AlquimiaGeochemicalConditionList_C* alquimia_conditions);


#endif  /* ALQUIMIA_DRIVERS_CC_BATCH_CHEM_H_ */
