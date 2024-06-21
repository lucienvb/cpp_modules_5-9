include makerc/colors.mk

################################################################################

NAME			:= mut
BUILD_DIR		:= build
INCLUDE_DIR		:= include
RM				:= rm -rvf

HEADERS			= $(INCLUDE_DIR)/MutantStack.hpp
CC				= c++

################################################################################

CFLAGS			= -Wall -Wextra -Werror -Wpedantic -std=c++11
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))

ifdef	DEBUG
	CFLAGS		+=-g
endif

# undefined: this enables UndefinedBehaviorSanitizer (UBSan),
# which checks for undefined behavior in your code.
ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

################################################################################

SRC = \
  src/main.cpp \

################################################################################

OBJS       = $(addprefix $(BUILD_DIR)/, $(SRC:%.cpp=%.o))

################################################################################

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(OBJS): $(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################

all: $(NAME)

clean:
	@$(RM) $(OBJS)

debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) DEBUG=1 FSAN=1

resan: fclean fsan

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug rebug fsan resan