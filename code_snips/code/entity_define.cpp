struct person_t {
  std::string name_first;
  std::string name_last;
};

struct user_t {
  std::string username;
  person_t person;
};

namespace nbdl {
  NBDL_ENTITY(person_t
  , name_first
  , name_last
  );
  NBDL_ENTITY(user_t
  , username
  , person
  );
}
