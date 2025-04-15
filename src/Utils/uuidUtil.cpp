#include <random>
#include <string>
#include <stduuid/uuid.h>

#include "uuidUtil.h"

std::string Utils::generate_uuid()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    uuids::uuid_random_generator generator{gen};
    uuids::uuid id = generator();
    return uuids::to_string(id);
}
